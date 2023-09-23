/*
비 내림차순으로 정렬된 수열 부분수열의 합은 k / 합이 k인 부분수열이 여러개인 경우 길이가 짧은 수열을 찾음
즉 비내림 차순이라는거는 뒤로 갈수록 점점 커진다는 뜻? 근데 같을 수도 있다는 의미인것 같음

만약에 크기가 더 크다면? 앞에의 원소를 하나씩 미뤄야하나?
1 2 3 4 5 7
1 -> 1
1 2 -> 3
1 2 3 -> 6
1 2 3 4 -> 10
원소 제거
2 3 4 -> 9
3 4 -> 7로 인해 7을 확정 한 후 일단 5까지 진행
3 4 5 -> 12
원소 제거
4 5 -> 9
5 -> 5 라서 안되는걸로 끝나는걸 로직으로 진행 예정
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;

    int sum = 0,pos = 0;
    int length = 1000000;
    int start = 0,end = 0;
    
    for(int i =0;i<sequence.size();i++){
        sum += sequence[i];
        if(sum == k &&length > i - pos){
            start = pos;
            end = i;
            length = i - pos;
        }
        if(sum > k){
            while(sum > k){
                sum -= sequence[pos];
                pos++;
                if(sum == k && length > i - pos){
                    start = pos;
                    end = i;
                    length = i - pos;
                }
            }
        }
    }
    answer.push_back(start);
    answer.push_back(end);
    return answer;
}