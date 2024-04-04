//문제풀이: https://githubseob.tistory.com/174

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, int>trees;
	string name("");
	int count(0);

	while (getline(cin, name)) {
		++trees[name];
		++count;
	}


	for (auto iter = trees.begin(); iter != trees.end(); ++iter) {
		cout << iter->first << " " << fixed << setprecision(4) << (double)iter->second * 100 / count << '\n';
	}
}