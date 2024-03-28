//문제풀이: https://githubseob.tistory.com/377

#include <iostream>
#include <vector>
#define DIV 9901
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0);
	cin >> N;
	
	vector<int>answer(100001, 0);
	answer[0] = 1;
	answer[1] = 3;	
	
	for (int idx = 2; idx <= N; ++idx) {
		answer[idx] = ((answer[idx - 1] * 2) % DIV + answer[idx - 2]) % DIV;		
	}
	cout << answer[N];
}