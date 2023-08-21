/*
n^2 배열 자르기

1행 1열부터 i행 i열 까지 모든 숫자를 i로 채움
문제의 예시 처럼

n = 3이면
1 2 3
2 2 3
3 3 3 이 되는것을
1 2 3 2 2 3 3 3 3인 한 배열로 저장을 한다. 그리고 left의 인덱스 부터 right의 인덱스 까지 배열을 자른다.

2 5 -> 3 2 2 3 이 되는것이다.

생각을 해보면 left가 2일때 right가 5일때 이차원 배열에 대해서
i,j라고 하면 i* n + j값이 left부터 i * n + j의 값이 right까지로 생각을 하면 되지 않을까 싶다.

즉, left <= i * 3 + j && i*3 + j <= right 라는 경우를 생각을 하면 안에 들때에 대해서면 push_back을 하면 되지 않나 싶다.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    //15~20 시간 초과로 인한 left에서 부터 연산을 시작하기 위해 설정
    //해당하는 행에 대해서면 연산을 진행하는 것으로 설정
    int left_i,left_j,right_i,right_j;
    left_i = left / n;
    right_i = right / n;
    
    for(int i =left_i;i<=right_i;i++){
        for(int j =0;j<n;j++){
             //left~right의 범위 안에 들을 때
            if(left <= i * n + j && i * n + j <= right){
                if(j > i){
                    //인덱스 + 1을 해야 1행일때 1 2행일때 2가 된다.
                    answer.push_back(j + 1);
                }else{
                    //마찬가지
                    answer.push_back(i + 1);
                }
            }
            if(i * n + j > right){
                //right보다 크다는 것은 더이상 연산이 필요가 없음 그냥 return을 해버리면 됨
                return answer;
            }
        }
    }
    return answer;
}