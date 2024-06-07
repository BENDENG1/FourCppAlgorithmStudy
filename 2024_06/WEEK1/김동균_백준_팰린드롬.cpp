// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <vector>

// using namespace std;
// bool isPalindrome(const string &s, int start, int end) {
//     // start와 end의 값을 정렬
//     if (start > end) {
//         swap(start, end);
//     }

//     // 부분 문자열이 팰린드롬인지 확인
//     while (start < end) {
//         if (s[start] != s[end]) {
//             return false;
//         }
//         start++;
//         end--;
//     }
//     return true;
// }

// int main()
// {
//     int N;
//     string t;
//     int temp;
//     cin >> N;
//     for(int i=0;i<N;i++)
//     {
//         cin >> temp;
//         t += to_string(temp);
//     }
//     int M;
//     cin >> M;
//     for(int i=0;i<M;i++)
//     {
//         int start,end;
//         cin >> start >> end;
//         cout << (isPalindrome(t,start,end) ? "1" : "0" )<< endl;
//     }
// }

#include<iostream>
#include<algorithm>
using namespace std;

int DP[2001][2001];
int num[2001];
int N, M;
int Start, End;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
		DP[i][i] = 1; // 한자리수는 무조건 펠린드롬

		// "1 1", "2 2", "4 4"와 같이 두자리가 같은 경우들 기록
		if (i != 1 && num[i - 1] == num[i]) 
			DP[i - 1][i] = 1;
	}
		

	for (int i = 2; i <= N - 1; i++)
	{
		for (int j = 1; i + j <= N ; j++)
		{
			if (num[j] == num[i + j] && DP[j + 1][i + j - 1] == 1)
				DP[j][i + j] = 1;
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> Start >> End;

		cout << DP[Start][End] << '\n';
	}

}