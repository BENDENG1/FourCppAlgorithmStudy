/*
주차 요금 계산

기본시간, 요금, 단위시간, 단위요금
출차 내역x -> 23:59출차 판단
기본시간 이하 -> 기본 요금
기본 초과 -> 기본 + 단위시간의 단위요금(올림으로 계산)

출력은 차량번호가 작은 순서부터!!

진짜 고통스러운 문제였다. 문자열 처리는 괜찮았지만 입차출차 왜 하루에 두번이상 받는건데 ㅡㅡ
*/
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

int calc_time(string hour, string minute);
int calc_cost(vector<int> fees,int time);

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int,int> m; //차 번호, 입출 시간 
    map<int,int> pair_io; //차 번호, 총 시간(분)
    int time = 0;
    int car = 0;
    int cost = 0;
    vector<string> s; //하나의 입출차 내역에 4가지를 push_back을 할 예정
    string token; // 자를때마다 받은 토큰들
    
    
    
    for(int i = 0 ; i < records.size();i++){
        s.clear();
        char delimeter = ':';
        istringstream iss(records[i]);
        while(getline(iss,token,delimeter)){
            //처음 ':'로 구분후 ' '이므로 이렇게 진행
            s.push_back(token);
            delimeter = ' ';
        }
        time = calc_time(s[0],s[1]);
        car = stoi(s[2]);
        if(s[3] == "IN"){
            m.insert(make_pair(car,time));
        }else{
            m[car] = time - m[car];
            if(pair_io.find(car) == pair_io.end()){
                pair_io.insert(make_pair(car,m[car]));
            }else{
                pair_io[car] = pair_io[car] + m[car];
            }
            m.erase(car);
        }
    }
    
    //이제 출차하지 않은 차들 "23:59"로 일괄적으로 처리
    for(auto it = m.begin(); it != m.end();it++){
        time = calc_time("23","59");
        time -= it -> second;
        if(pair_io.find(it->first) != pair_io.end()){
            time += pair_io[it->first];
        }
        pair_io[it->first] = time;
    }
    
    for(auto it = pair_io.begin();it!=pair_io.end();it++){
        cost = calc_cost(fees,it->second);
        answer.push_back(cost);
    }
    return answer;
}

int calc_time(string hour, string minute){
    int sum = stoi(hour) * 60 + stoi(minute);
    return sum;
}

int calc_cost(vector<int> fees,int time){
    if(time <= fees[0]) //기본 요금일때
        return fees[1];
    //기본요금 아닐때 계산 , 기본요금 + 단위요금 return
    int unitFee = 0;
    time -= fees[0];
    unitFee = ((time/fees[2]) + (time % fees[2] > 0 ? 1 : 0)) * fees[3]; //올림을 해줘야함 
    cout <<unitFee<<"    ";
    return fees[1] + unitFee;
}
