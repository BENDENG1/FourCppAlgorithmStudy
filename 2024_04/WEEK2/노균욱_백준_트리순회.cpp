/*
걍 재귀
*/
#include <iostream>
#include <vector>

using namespace std;

struct Node{
    char root;
    char left;
    char right;
};

void preOrder(const vector<Node> &v, char root){
    if(root == '.')
        return;
    int idx = (int)(root - 'A');
    cout << root;
    preOrder(v, v[idx].left);
    preOrder(v, v[idx].right);
}

void middleOrder(const vector<Node> &v, char root){
    if(root == '.')
        return;
    int idx = (int)(root - 'A');
    middleOrder(v, v[idx].left);
    cout<<root;
    middleOrder(v, v[idx].right);
}

void postOrder(const vector<Node> &v, char root){
    if(root == '.')
        return;
    int idx = (int)(root - 'A');
    postOrder(v, v[idx].left);
    postOrder(v, v[idx].right);
    cout<<root;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    char root,left,right;
    cin >> n;
    vector<Node> v(27);
    

    for(int i = 0; i < n; i++){
        cin >> root >> left >> right;
        int idx = (int)(root - 'A');
        v[idx].root = root;
        v[idx].left = left;
        v[idx].right = right;
    }

    preOrder(v, 'A');
    cout<<"\n";
    middleOrder(v, 'A');
    cout<<"\n";
    postOrder(v, 'A');
}