//문제풀이: https://githubseob.tistory.com/28

#include <iostream>
#include <vector>
using namespace std;

void Preorder(char node, const vector<vector<char>>& tree) {
	cout << node;
	if (tree[node - 'A'][0] != '.') {
		Preorder(tree[node - 'A'][0], tree);
	}
	if (tree[node - 'A'][1] != '.') {
		Preorder(tree[node - 'A'][1], tree);
	}
}

void Inorder(char node, const vector<vector<char>>& tree) {
	if (tree[node - 'A'][0] != '.') {
		Inorder(tree[node - 'A'][0], tree);
	}
	cout << node;
	if (tree[node - 'A'][1] != '.') {
		Inorder(tree[node - 'A'][1], tree);
	}
}

void Postorder(char node, const vector<vector<char>>& tree) {
	if (tree[node - 'A'][0] != '.') {
		Postorder(tree[node - 'A'][0], tree);
	}
	if (tree[node - 'A'][1] != '.') {
		Postorder(tree[node - 'A'][1], tree);
	}
	cout << node;
}

int main() {
	int N(0);
	cin >> N;
	vector<vector<char>>tree(N, vector<char>(2, ' '));

	char parent(' '), left_child(' '), right_child(' ');
	for (int idx = 0; idx < N; ++idx) {
		cin >> parent >> left_child >> right_child;
		tree[parent - 'A'][0] = left_child;
		tree[parent - 'A'][1] = right_child;
	}

	Preorder('A', tree);
	cout << '\n';
	Inorder('A', tree);
	cout << '\n';
	Postorder('A', tree);
}