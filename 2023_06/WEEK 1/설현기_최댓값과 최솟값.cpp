#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
	string answer = "";
	string temp = "";
	vector<int>nums;

	// ���� �߰� ������ ���ڿ��� �����ϰ���� �߽߰� ������ ���ڿ��� ���ڷ� ��ȯ�Ͽ� ����
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
	// ����
	sort(nums.begin(), nums.end());
	answer = to_string(nums.front()) + " " + to_string(nums.back());
	return answer;
}