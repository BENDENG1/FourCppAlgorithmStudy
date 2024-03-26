/*
동물원

가로 2 세로 n인데 사자를 배치할 수 있는 케이스 

사자를 배치할 수 있는 모든 경우의 수인데

dp? ㅇㅇ dp 10만개에 대해서 내가 

1   1 -> 2

하나를 두는 케이스는 n개

왼쪽을 두냐 안두냐의 케이스로 오른쪽도 마찬가지
dp ㅇㅇ
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int answer = 0;
    int n;
    cin >> n;

    vector<int> v(n+1,0);

    v[0] = 1;
    v[1] = 3;

    for(int i = 2; i <= n; i++){
        v[i] = (v[i - 1] * 2 + v[i - 2]) % 9901;
    }

    cout<<v[n];
}