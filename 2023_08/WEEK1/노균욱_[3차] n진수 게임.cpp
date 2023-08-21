/*
n진수 게임

n진법, 구할 숫자의 갯수t, 참가하는 인원m,튜브의 순서 p

1번 예제를 보자
4까지 구하는 거니
0 /(0)1/10/11/100이 되는건데
여기서 둘이서 하는데 첫번째 순서이니
0       1  1  1이 되어서 0111이 되는 것이다.

*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string num_conversion(int n, int num);

string solution(int n, int t, int m, int p) {
    string answer = "";
    int cnt = 0;
    int num = 0;
    int turn = 0;
    string s;
    
    while(1){
        s = num_conversion(n,num);
        for(int i = 0;i < s.length();i++){
            turn++;
            if(turn > m)
                turn = 1;
            if(turn == p){
                cnt++;
                answer.push_back(s[i]);
            }
            if(cnt == t)
                return answer;
        }
        num++;
    }
}

string num_conversion(int n, int num){
    string arithmetic = "0123456789ABCDEF";
    string con_num = "";
    if(num == 0){ //0일때도 포함해야해서 return;
        return "0";
    }
    while(num > 0){
        con_num += arithmetic[num % n];
        num /= n;
    }
    reverse(con_num.begin(),con_num.end());
    return con_num;
}