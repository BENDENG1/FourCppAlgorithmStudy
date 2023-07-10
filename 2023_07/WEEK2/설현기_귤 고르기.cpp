/* 우선 맵을 만들어 귤의 크기를 담은 배열을 가져와 [크기, 갯수] 로 정의하도록 하였다.
그다음 각 크기에 맞는 갯수들로 구성된 벡터를 하나 만들고, 이 벡터를 내림차순으로 정렬하였다.
그리고 벡터의 크기만큼 반복하며 갯수를 계속 더하는데 상자에 담으려는 귤의 개수를 넘으면 반복문을 중단시키는데,
개수를 더할때마다 answer에 +1을 해주며 종류의 수를 구한다.*/
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;
    vector<int> g;
    for(int i = 0; i < tangerine.size(); i++){
        m[tangerine[i]]++;
    }
    for(int i = 0; i < m.size(); i++){
        g.push_back(m[i]);
    }
    sort(g.rbegin(), g.rend());
    int cnt = 0;
    for(int i = 0; i < g.size(); i++){
        if(cnt >= k)
            break;
        cnt += g[i];
        answer++;
    }
    return answer;
}