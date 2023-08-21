/*
2개에서 시간초과를 한다.. 생각해보면 조금 억지가 아닌가 싶긴하다.
생각을 해보니 처음에 들어온 tangerine에 대해서 sort를 진행하고 그냥 ++을 하면 이 번거러운 과정을 수고하지 않을 수 있지 않나?!
바보다..
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b){
    return a[1] > b[1]; //두번째 원소 즉, 갯수를 위주로 정렬
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    vector<vector<int>> v;
    sort(tangerine.begin(),tangerine.end());
    v.push_back({tangerine[0],1}); // 정렬후 첫 원소 push_back index1부터 비교할 예정
    
    int before_num = tangerine[0];
    int v_index = 0;
    for(int i = 1; i < tangerine.size();i++){
        if(tangerine[i] != before_num){
            v.push_back({tangerine[i],1});
            before_num = tangerine[i];
            v_index++;
        }else{
            v[v_index][1]++;
        }
    }

    
    sort(v.begin(),v.end(),compare);
    int i = 0;
    while (k > 0 && i < v.size()){
        k -= v[i][1];
        answer++;
        i++;
    }
    
    return answer;
}