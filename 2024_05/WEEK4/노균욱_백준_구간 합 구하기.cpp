/*
구간 합 구하기

n개의 수

m은 변경이 일어나는 횟수 / k는 구간의 합을 구하는 횟수

a가 1인 경우 B번째 수를 C번째로 바꾸고 
a가 2인 경우 B번째부터 C번째 수까지의 합을 출력하면 됨

dp 느낌으로 하면 되지 않을까
https://www.acmicpc.net/blog/view/9
*/
#include <iostream>
#include <vector>

using namespace std;
vector<long long> v;



int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n, m, k;
    long long tmp;
    cin >> n >> m >> k;
    v.push_back(0);
    for(int i = 0 ; i < n; i++){
        cin >> tmp;
        v.emplace_back(tmp + v[i - 1]);
    }

    for(int i = 0; i < m + k; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if(a == 1){
            long long diff = c - v[b];
            for(int k = b; k <= n; k++){
                v[k] += diff;
            }
        }else{
            long long sum = v[c] - v[b - 1];
            cout << sum << "\n";
        }
    }
}