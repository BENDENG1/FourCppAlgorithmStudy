/*
가장 긴 증가하는 수열 2

dp로 풀면? -> 시간 초과 100만 * 100만이라서 그런듯
이분 탐색 -> 정답 

대단한   풀이가 인터넷에 있어서 스터디 공유 + 공부 겸 진행

LIS는 lower_bound를 통해 새로운 값을 삽입할 위치를 찾아줌 
-> 결국 이분탐색과 스타일은 같지만 아주 숏코딩이라서 참고
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, tmp;
    cin >> n;

    vector<int> v;

    for(int i = 0 ; i < n; i++){
        cin >> tmp;
        
        if(i == 0 || tmp > v.back()){
            v.push_back(tmp);
        }else{
            *(lower_bound(v.begin(), v.end(), tmp)) = tmp;
        }
    }

    cout << v.size();
}



/*
int bSearch(int start, int end, int find, const vector<int> & list){
    int mid;

    while(start < end){
        mid = (start + end) / 2;
        if(list[mid] < find){
            start = mid + 1;
        }else{
            end = mid;
        }
    }
    return end;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, tmp, answer = 0;
    cin >> n;

    vector<int> v(n + 1, 0);
    vector<int> list(n + 1, 0);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    list[0] = v[0];
    for(int i = 0 ; i < n ; i++){
        if (list[answer] < v[i]){
            list[answer + 1]  = v[i];
            answer++;
        }
        else{
            list[bSearch(0, answer, v[i], list)] = v[i];
        }
    }

    cout << answer + 1;
}

*/

/*

struct Sequence{
    int num;
    int cnt;
};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, tmp, answer = 0;
    cin >> n;

    vector<int> numV(n, 0);
    vector<Sequence> v(n);

    for(int i = 0 ; i < n; i++){
        cin >> tmp;
        numV[i] = tmp;
        v[i].cnt = 1;
        v[i].num = tmp;
    }

    for(int i = 1 ; i < n; i++){
        int num, cnt = 1;
        for(int j = 0 ; j < i;j++){
            if(numV[i] > numV[j] && v[i].cnt < v[j].cnt + 1){
                v[i].cnt = v[j].cnt + 1;
            }
        }
        answer = answer < v[i].cnt ? v[i].cnt : answer;
    }

    cout << answer;
}
*/
