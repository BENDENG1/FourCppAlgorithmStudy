#include <iostream>>
#include<map>
#include<string>
using namespace std;

map<string, int> m;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	int cnt(0);
	while (getline(cin, s)) {
		if (m.find(s) == m.end()) {
			m[s] = 1;
		} //문자열 찾기를 통해 찾기
		else {
			++m[s];
		}

		++cnt; //종 갯수
	}

	cout << fixed; 
	cout.precision(4);//소수 4번째
	for (auto it = m.begin(); it != m.end(); ++it) {
		cout << it->first << ' ' << it->second * 100 / (double)cnt << '\n';
	}

	return 0;
}
// #include <iostream>
// #include<map>
// #include<string>
// #include<format>
// using namespace std;

// int main()
// {
//     map<string, int> m;
// 	string s;
// 	int cnt(0);
// 	while (getline(cin, s)) {
// 		if (m.find(s) == m.end()) {
// 			m[s] = 1;
// 		} //문자열 찾기를 통해 찾기
// 		else {
// 			++m[s];
// 		}
// 		++cnt; 
// 	}

// 	cout << fixed; 
// 	cout.precision(4);//소수 4번째
// 	for (auto it = m.begin(); it != m.end(); ++it) {
// 		cout << format("{} {}",it->first,t->second * 100 / (size_t)cnt);
// 	}

// 	return 0;
// }

//format사용 불가
