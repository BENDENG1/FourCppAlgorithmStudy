//문제풀이: https://githubseob.tistory.com/383

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

bool cmp(const string& l1,const string& l2) {
	return l1.size() < l2.size();
}

int main() {
	int T(0);
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int N(0);
		cin >> N;
		
		vector<string>list(N, "");
		for (int idx = 0; idx < N; ++idx) {
			cin >> list[idx];
		}

		sort(list.begin(), list.end(), cmp);

		unordered_set<string>set_list;		
		string answer("YES");
		for (int idx = 0; idx < N; ++idx) {
			string number("");
			for (int num_idx = 0; num_idx < list[idx].size(); ++num_idx) {
				number += list[idx][num_idx];				
				if (set_list.find(number) != set_list.end()) {
					answer = "NO";
					break;
				}
			}
			if (answer == "NO") break;
			set_list.insert(list[idx]);
		}
		cout << answer <<'\n';
	}
}