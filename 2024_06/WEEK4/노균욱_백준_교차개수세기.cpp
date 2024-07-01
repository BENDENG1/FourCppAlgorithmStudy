/*
교차 개수 세기

교차하는 총 개수를 구하는 것.

음 교차하는 개수니깐

둘의 숫자가 하나는 크고 하나는 작아야 교차를하는 특징이 있음

위에서부터 답을 찾으니 나보다 작은 숫자에 대해서 더 높은 곳이 있는지 체킹을 하면?
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Line{
    int start;
    int end;
};

bool cmp(const Line &a, const Line &b){
    if(a.start == b.start)
        return a.end < b.end;
    return a.start < b.start;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n, m, start, end, ans = 0,pos,line = 0;

    cin >> n >> m;
    set<int> s;

    vector<Line> v;
    for(int i = 0 ; i < m; i++){
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(),v.end(), cmp);

    for(int i = 0; i < v.size(); i++){
        if (s.find(v[i].start) == s.end()) {
            line = 0;
            for (int j = i + 1; j < v.size(); j++)
            {
                if (v[i].end > v[j].end)
                {
                    ans++;
                    line++;
                    pos = j;
                }
            }
        }
        else{
            ans += line;
            for (int j = pos + 1; j < v.size(); j++)
            {
                if (v[i].start != v[j].start && v[i].end > v[j].end)
                {
                    ans++;
                    line++;
                    pos = j;
                }
            }
        }
        s.insert(v[i].start);
    }
    cout << ans;
}



/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int countIntersection(const vector<int> *v, int start, int end, int size);

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n, m, start, end, ans = 0;

    cin >> n >> m;
    vector<int> v[n + 1];

    for(int i = 0; i < m; i++){
        cin >> start >> end;
        v[start].push_back(end);
    }

    for(int i = 1 ; i <= n; i++){
        if(v[i].empty())
            continue;
        sort(v[i].begin(), v[i].end());
        for(int j : v[i]) {
            ans += countIntersection(v, i, j , n);
        }
    }
    cout << ans;
}

int countIntersection(const vector<int> *v, int start, int end, int size){
    int cnt = 0;

    for(int i = start  + 1; i <= size; i++){
        for(int num : v[i]){
            if(num < end){
                cnt++;
            }else 
                break;
        }
    }

    return cnt;
}
*/

