#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
	string answer = "";
	string temp = "";
	vector<int>nums;

	// 공백 발견 전까지 문자열을 저장하고공백 발견시 저장한 문자열을 숫자로 변환하여 저장
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			nums.push_back(stoi(temp));
			temp.clear();
		}
		else
		{
			temp += s[i];
		}
	}
	nums.push_back(stoi(temp));
	// 정렬
	sort(nums.begin(), nums.end());
	answer = to_string(nums.front()) + " " + to_string(nums.back());
	return answer;
}