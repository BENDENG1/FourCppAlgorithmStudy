/*
0을 모두 제거 한 후 길이를 2진법으로 표현
예시와 함께 이해
예시 1
110010101001 -> 111111 -> 110 -> 11 -> 10 -> 1
첫번째 : 110010101001 -> 111111 제거된 0 갯수 : 000000 -> 6개
두번째 : 110 -> 11  제거된 0 갯수 : 0 -> 1개
세번째  :10 -> 1  제거된 0 갯수 : 1개

결국 변환횟수와 변환과정에서 제거된 0의 갯수 return
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string str = "";
    int removeCnt = 0; //0을 제거한 갯수
    int removeTime = 0; //0을 지운 횟수
    int changeCnt = 0; //길이 변환을 한 횟수
    
    //길이가 1일경우 최소1이 포함되므로 바로 끝냄
    if(s.length() == 1){
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    
    while(s.length() != 1){
        //지운게 크다면 remove먼저 하고 같다면 길이를 변환 진행
        str = "";
        if(removeTime > changeCnt){
            int s_len = s.length();
            while(s_len != 0){
                // 12 -> 8 4 0 0 
                // 0 6 / 0 3 / 1 1 / 1 0
                str += (s_len % 2) + '0';
                s_len /= 2;
            }
            changeCnt++;
        }else{
            for(int i = 0; i < s.length();i++){
                if(s[i] == '1'){
                   str += '1';
                }else{
                    removeCnt++;
                }
            }
            removeTime++;
        }
        s = str;
    }
    changeCnt++; // 마지막의 0을 제거해서 1이라고 끝나는것이 아니라 한번 이진변환을 꼭 해줘야 함
    answer.push_back(changeCnt);
    answer.push_back(removeCnt);
    return answer;
}