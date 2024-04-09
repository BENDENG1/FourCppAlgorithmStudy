#include <iostream>
#include <vector>
using namespace std;

struct node {
    char alphabet;  // 알파벳
    node* left; // 왼쪽 자식 노드 포인터
    node* right; // 오른쪽 자식 노드 포인터

    node() : alphabet('\0'), left(NULL), right(NULL) {};
    
    node(char alphabet, node* left = NULL, node* right = NULL)
        : alphabet(alphabet), left(left), right(right) {}
};

node* getChildNode(vector<node>& nodes, char ch) {
    return ch == '.' ? NULL : &nodes[ch - 'A'];
}

void PreOrder(node* n) {
    if (n != NULL) {
        cout << n->alphabet;
        PreOrder(n->left);
        PreOrder(n->right);
    }
}
// 루트 - 왼쪽 자식 - 오른쪽 자식
void InOrder(node* n) {
    if (n != NULL) {
        InOrder(n->left);
        cout << n->alphabet;
        InOrder(n->right);
    }
}
// 왼쪽 자식 - 루트 - 오른쪽 자식
void PostOrder(node* n) {
    if (n != NULL) {
        PostOrder(n->left);
        PostOrder(n->right);
        cout << n->alphabet;
    }
}
// 왼쪽 자식 - 오른쪽 자식 - 루트
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<node> nodes(N); 

    for (int i = 0; i < N; i++) {
        char alphabet, left, right;
        cin >> alphabet >> left >> right;
        int index = alphabet - 'A'; 
        nodes[index] = node(alphabet, getChildNode(nodes, left),
                            getChildNode(nodes, right));
    }

    PreOrder(&nodes[0]); cout << "\n";
    InOrder(&nodes[0]); cout << "\n";
    PostOrder(&nodes[0]); cout << "\n";

    return 0;
}