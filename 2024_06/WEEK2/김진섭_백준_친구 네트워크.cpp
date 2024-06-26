#include <iostream>
#include <map>
using namespace std;
map<string, string>parent;
map<string, int>groupCount;

string find(string name) {	
	if (parent[name] == name) return name;
	return parent[name] = find(parent[name]);
}

bool isUnion(string name1, string name2) {
	return find(name1) == find(name2);
}

void Union(string name1, string name2) {	
	if (isUnion(name1, name2)) return;
	string parentName1 = find(name1);
	string parentName2 = find(name2);
	if (parentName1 < parentName2) swap(parentName1, parentName2);
	groupCount[parentName2] += groupCount[parentName1];
	parent[parentName1] = parentName2;	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T(0);
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int F(0);
		cin >> F;

		parent.clear();
		groupCount.clear();

		for (int idx = 0; idx < F; ++idx) {
			string name1(""), name2("");
			cin >> name1 >> name2;
			if (parent.find(name1) == parent.end()) {
				parent[name1] = name1;
				groupCount[name1] = 1;
			}
			if (parent.find(name2) == parent.end()) {
				parent[name2] = name2;
				groupCount[name2] = 1;
			}
			if (!isUnion(name1, name2)) Union(name1, name2);
			cout << groupCount[find(name1)] << '\n';
		}
	}
}