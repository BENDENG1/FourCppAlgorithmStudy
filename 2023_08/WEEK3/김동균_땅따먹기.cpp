#include <vector>
#include <set>
#include <cmath>

using namespace std;
// 'v'에서 'idx'를 제외한 요소 중 최댓값을 찾는 함수
int max_check(vector<int>& v, int idx){
    int temp = 0;
    for(int i = 0; i < 4; i++)
        if(i != idx)
            temp = max(temp, v[i]);
    return temp;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for(size_t i = 0; i < land.size(); i++){
        for(int j = 0; j < 4; j++){
            land[i][j] += max_check(land[i], j);
            answer = max(answer, land[i][j]);
        }
    }
    return answer;
}