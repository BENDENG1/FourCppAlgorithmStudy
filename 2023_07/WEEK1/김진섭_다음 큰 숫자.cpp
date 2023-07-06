//문제풀이: https://githubseob.tistory.com/251

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {
	int idx(0), btoi(1), answer(0);
	vector<int>num;

	while (n > 0) { // 십진수 -> 이진수 변환
		num.push_back(n % 2);
		n /= 2;
	}
	num.push_back(0); // +1씩 더할때 자릿수가 늘어날 수 있으므로
	reverse(num.begin(), num.end()); // 역순인거 정상화

	next_permutation(num.begin(), num.end()); // 오름차순 이동 한번

	for (idx = num.size() - 1; idx >= 0; --idx) { // 이진수 -> 십진수 변환
		answer += (num[idx] * btoi);
		btoi *= 2;
	}
	return answer;
}