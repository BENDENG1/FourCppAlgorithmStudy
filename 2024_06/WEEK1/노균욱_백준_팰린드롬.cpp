/*
팰린드롬

팰린드롬이란 역으로 읽어도 똑같은 것을 말함

음..
질문이 백만개 2000이면 100만 * 2000 -> 20억이라는 건데 그냥 다 탐색은 아닐듯 ㅇㅇ

1 2 1 3 1 2 1 일 때 

길이가 1 -> 팰린드
길이가 2 -> 두개가 같으면 팰린드
길이가 3 -> 양 옆이 같고 사이가 팰린드라면 팰린드 i , j 라면 i+1 ~ j+1이 팰린드라면 팰린드지.
*/
#include <iostream>
#include <vector>

using namespace std;

bool dp[2001][2001] = {false,};

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m, tmp, start, end;
    vector<int> v;
    
    cin >> n;
    for(int i = 0 ; i < n; i ++){
        cin >> tmp;
        v.emplace_back(tmp);
    }

    for(int i = 0 ; i < n; i++){
        dp[i][i] = true;
        if(i > 0 && v[i - 1] == v[i]) {
            dp[i - 1][i] = true;
        }
    }
    for(int i = 2; i < n; i++){
        for(int j = 0; i + j < n;j++){
            if(v[j] == v[i + j] && dp[j + 1][i + j - 1]){
                dp[j][i + j] = true;
            }
        }
    }
    cin >> m;

    for(int i = 0 ; i < m;i++){
        cin >> start >> end;
        if(dp[start - 1][end - 1])
            cout<<"1\n";
        else
            cout<<"0\n";
    }
}