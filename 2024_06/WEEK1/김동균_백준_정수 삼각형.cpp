#include <iostream>
#include <algorithm>
int Triangle[500][500];
int DP[500][500];
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

	//입력
	int n; cin >> n;
	for (int i = 1; i <= n; i++) { //높이
		for (int j = 1; j <= i; j++) { //가로
			cin >> DP[i][j];
		}
	}

	//문제 해결
	int mmax = DP[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i+1; j++) {
			if (j == 1) DP[i][j] += DP[i - 1][j] ;
			else if (j == i) DP[i][j] += DP[i - 1][j-1] ;
			else DP[i][j] += max(DP[i - 1][j-1], DP[i - 1][j]);
			mmax = max(mmax, DP[i][j]);
		}
	}
    
    	//결과 출력
	cout << mmax << '\n';
}
