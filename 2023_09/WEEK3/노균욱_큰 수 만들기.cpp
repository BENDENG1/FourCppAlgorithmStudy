/*
그냥 map으로 갯수 추가해주면 될듯 ㅇㅇ 그리고 9999988887777이런순으로 하면 끝
처럼 단순한 문제가 아니라 숫자를 몇개 뺄지 생각하는 문제임 ㅇㅇ

4177252841에 4라 치면

41775중에 
..7.이 최댓값 idx 시작지점이 되는거임
그런식의 계속 비교를 함

번외)만약 41779252841이면
4177지워버리고
....9252841되는거임

*/
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.size() - k;
    int idx = -1;
    
    for(int i = 0 ; i < size;i++){
        char maxNum = '0';
        for(int j = idx + 1;j <=k+i;j++){
            if(maxNum < number[j]){
                maxNum = number[j];
                idx = j;
            }
        }
        answer+=maxNum;
    }
    return answer;
}