#include <iostream>
#include <vector>
using namespace std;

struct node{
	char left;
	char right;
};

vector<node> v(26);

void preorder(char node){ // 전위 순회
	if(node == '.') return;
	
	cout << node;
	preorder(v[node].left);
	preorder(v[node].right);
}

void inorder(char node){ // 중위 순회
	if(node == '.') return;
	
	inorder(v[node].left);
	cout << node;
	inorder(v[node].right);
}

void postorder(char node){ // 후위 순회
	if(node == '.') return;
	
	postorder(v[node].left);
	postorder(v[node].right);
	cout << node;
}
int main(){
    int n;
    char root, l, r;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> root >> l >> r;
        v[root].left = l;
        v[root].right = r;
    }
    
    preorder('A');
	cout << "\n";
	
	inorder('A');
	cout << "\n";
	
	postorder('A');
	
	return 0;
}