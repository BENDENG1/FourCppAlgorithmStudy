#include <iostream>
#include <map>

using namespace std;

int num[41];
int N, S;
map<int, int> total;
long long cnt = 0;

void leftSum(int s, int sum) {
	if (s == N / 2) {
		total[sum]++;
		return;
	}
	leftSum(s + 1, sum);
	leftSum(s + 1, sum + num[s]);
}

void rightSum(int s, int sum) {
	if (s == N) {
		cnt += total[S - sum];
		return;
	}
	rightSum(s + 1, sum);
	rightSum(s + 1, sum + num[s]);
}

int main() {
	cin >> N >> S;
    
	for (int i = 0; i < N; i++){
        cin >> num[i];
    }
	
	leftSum(0, 0);
	rightSum(N / 2, 0);
    
	if (S == 0)
		cout << cnt - 1;
	else
		cout << cnt;
    
    return 0;
}