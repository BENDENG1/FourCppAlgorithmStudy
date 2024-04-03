/*
전화번호 목록

음 그냥 하라는대로 했을 때는 시간초과 -> 정렬을 없앴는데 시간 초과 -> 초과

음 갈아엎을까

아 입력을 받을때마다 비교 -> push 가 아니라

다 집어 넣고 sort를 한번하고 비교를 하는것이 편할듯 왜냐면 사전순 정렬이니?

https://restudycafe.tistory.com/486 -> Trie 풀이법인데 이거 공부하기
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve(vector<string> &v, int n);

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);

    int t, n;
    vector<string> v;

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        v.clear();
        solve(v,n);
    }
}

void solve(vector<string> &v, int n){
    string number;
    bool isNo = false;
    int len = 0;

    for(int i = 0 ; i < n ; i++){
        cin >> number;
        v.push_back(number);
    }
    sort(v.begin(), v.end());

    for(int i = 0 ; i < n - 1; i++){
        string first = v[i];
        string next = v[i + 1];

        if(first.size() < next.size()){
            if(first == next.substr(0,first.size())){
                cout <<"NO\n";
                return;
            }
        }
    }
    cout <<"YES\n";
}

/*
void solve(vector<string> &v, int n){
    string number;
    bool isNo = false;
    int len = 0;

    for(int i = 0 ; i < n ; i++){
        cin >> number;
        int idx = 0;
        if(!isNo){
            while(idx < v.size()){
                len = v[idx].length() < number.length() ? v[idx].length() : number.length();
                if(v[idx].substr(0,len) == number.substr(0,len)){
                    isNo = true;
                    break;
                }
                idx++;
            }
           v.push_back(number);
        }
    }

    sort(v.begin(), v.end());

    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i]<<"\n";
    }
    cout<<"\n\n";

    if(isNo){
        cout <<"NO\n";
    }else{
        cout <<"YES\n";
    }
    return;
}
*/