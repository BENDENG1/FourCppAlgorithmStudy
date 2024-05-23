/*



*/
#include <iostream>
#include <vector>
#include <cmath>

#define MAX 1000000000
#define MIN 0

using namespace std;

struct Num{
    int minNum;
    int maxNum;
};

vector<int> v;
vector<Num> tree;

void init(int node, int start, int end){
    if(start == end){
        tree[node].maxNum = v[start];
        tree[node].minNum = v[start];
        return ;
    }else{
        init(node * 2 , start, (start + end) / 2);
        init(node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node].minNum = min(tree[node * 2].minNum, tree[node * 2 + 1].minNum);
        tree[node].maxNum = max(tree[node * 2].maxNum, tree[node * 2 + 1].maxNum);
        return;
    }
}

Num findMinMaxNum(int node, int start, int end, int left, int right){
    if(left > end || right < start){
        return {MAX, 0};
    }else if (left <= start && end <= right){
        return {tree[node].minNum, tree[node].maxNum};
    }else{
        Num leftNum = findMinMaxNum(node * 2, start, (start + end) / 2 , left, right);
        Num rightNum = findMinMaxNum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
        return {min(leftNum.minNum, rightNum.minNum), max(leftNum.maxNum, rightNum.maxNum)};
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m, tmp, time;

    cin >> n >> m;
    
    int h = (int)ceil(log2(n));
    int tree_size = (1 << h + 1);
    v.resize(n, 0);
    tree.resize(tree_size);

    for(int i  = 0 ; i < n; i++){
        cin >> tmp;
        v[i] = tmp;
    }
    init(1, 0, n-1);

    for(int i = 0 ; i < m; i ++){
        int a, b;
        cin >> a >> b;
        Num num = findMinMaxNum(1, 0 , n-1, a - 1 , b - 1);
        cout << num.minNum <<" "<< num.maxNum <<"\n";
    }

}