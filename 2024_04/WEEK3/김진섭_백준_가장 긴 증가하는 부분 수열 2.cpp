#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0);
	cin >> N;
	vector<int>seq(N, 0);
	
	for(int idx=0;idx<N;++idx){
		cin >> seq[idx];		
	}

	vector<int>answer;
	answer.push_back(seq[0]);
	for (int idx =1; idx < N; ++idx) {		
		if (answer.back() < seq[idx]) {
			answer.push_back(seq[idx]);
		}
		else if (answer.back() > seq[idx]) {
			int lower = lower_bound(answer.begin(), answer.end(), seq[idx]) - answer.begin();
			answer[lower] = seq[idx];
		}
	}

	cout << answer.size();
}