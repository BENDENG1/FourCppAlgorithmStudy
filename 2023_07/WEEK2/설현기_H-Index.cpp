/* 우선 입력된 벡터를 오름차순으로 정렬한 후, 앞 인덱스부터 차례대로 탐색하여 H-Index는 citations 크기 - 인덱스로
설정했다(전 인덱스의 인용 횟수는 현재 인덱스의 인용 횟수보다 작기때문). 현재 인덱스의 인용 횟수가 H-Index 이상이면
H-Index를 return 하도록 한다.*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for(int i = 0; i < citations.size(); i++){
        int H_Index = citations.size() - i;
        if(citations[i] >= H_Index) return H_Index;
    }
    return answer;
    
}