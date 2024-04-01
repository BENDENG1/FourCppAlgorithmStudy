#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
	int N(0);
	cin >> N;
	vector<ll>count(10, 0);

	int place(1), add(0);
	for (N; N > 0; N /= 10) {		
		for (int num = 0; num <= 9; ++num) {			
			if (num < N % 10) {
				count[num] += (N / 10 + 1) * place;
			}
			else if (num == N % 10) {																
				count[num] += (N / 10) * place + add + 1;
			}
			else if (num > N % 10) {				
				count[num] += (N / 10) * place;
			}			
		}
		count[0] -= place;
		add += N % 10 * place;		
		place *= 10;		
	}

	for (int idx = 0; idx <= 9; ++idx) {
		cout << count[idx] << ' ';
	}	
}