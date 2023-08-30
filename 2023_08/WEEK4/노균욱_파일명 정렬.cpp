/*
파일명 정렬
숫자순으로 정렬 -> 파일명에 포함된 숫자를 반영한 정렬 기능을 저장소 관리 프로그램 구현
대소문자,숫자,공백,마침표,빼기부호
head -> 숫자가 아닌 문자 최소 한글자 이상
number -> 한글자에서 최대 다섯글자 0 ~ 99999 숫자! => 0001은 000 무시 1임
tail은 나머지 -> 아무 글자도 없을 수 있음

대소문자를 구분하지 않음 -> 소문자 통일해야겠다.
head : 사전 순으로 정렬 , number : 숫자순 정렬
head -> number순이고 둘다 같으면 주어진 시간순.

1. head,number,tail,index를 struct가 형인 vector에 넣는다
2. 정렬한다. (head순 -> 같다면 number순 -> 두개다 같다면 index순 정렬 끝!)
*/
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <string>

using namespace std;


struct Dict {
    string head;
    string number;
    string tail;
    int index;
};

bool isNumber(char c){
    return('0' <= c && c <= '9');
}

bool compareDicts(const Dict& a, const Dict& b) {
    string strA = a.head;
    string strB = b.head;
    int numA = stoi(a.number);
    int numB = stoi(b.number);

    
    //비교시에만 소문자로 비교를 하고 원래의 값을 리턴해야함
    for (char& c : strA) {
        c = tolower(c);
    }
    for (char& c : strB) {
        c = tolower(c);
    }
    
    //정렬의 순서에 대해서 다 넣음
    if (strA == strB) {
        if (numA == numB) {
            return a.index < b.index; //head같,number같 -> index순
        } else {
            return numA < numB;  // head같 -> number순
        }
    } else {
        return strA < strB;  // head순
    }
}


vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<Dict> v;
    string head_tmp = "";
    string number_tmp = "";
    string tail_tmp = "";

    //head,number,tail,index vector에 push_back
    for(int i = 0; i < files.size();i++){
        int j = 0;
        head_tmp = ""; //head 초기화
        while(!isNumber(files[i][j])){
            head_tmp += files[i][j];
            j++;
        }
        number_tmp = ""; // num초기화
        while(isNumber(files[i][j]) && number_tmp.length() < 5){
            number_tmp += files[i][j];
            j++;
        }
        tail_tmp ="";
        while(files[i][j]){
            tail_tmp += files[i][j];
            j++;
        }
        Dict tmpDict{head_tmp, number_tmp,tail_tmp,i};
        v.push_back(tmpDict);
    }
    
    sort(v.begin(),v.end(),compareDicts);
    
    for(const auto& dict : v) {
        answer.push_back(files[dict.index]);
    }
    return answer;
}
