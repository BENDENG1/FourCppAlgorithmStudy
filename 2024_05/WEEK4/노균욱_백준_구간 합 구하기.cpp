/*
구간 합 구하기

n개의 수

m은 변경이 일어나는 횟수 / k는 구간의 합을 구하는 횟수

a가 1인 경우 B번째 수를 C번째로 바꾸고 
a가 2인 경우 B번째부터 C번째 수까지의 합을 출력하면 됨

dp 느낌으로 하면 되지 않을까
https://www.acmicpc.net/blog/view/9
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<long long> v;
vector<long long> tree;

long long init(int node, int start, int end){
    if(start == end){
        tree[node] = v[start];
    }else{
        tree[node] = init(node * 2 , start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
    }
    return tree[node];
}

void update(int node, int start, int end, int idx, long long diff){
    if (idx < start || idx > end)
        return;
    tree[node] = tree[node] + diff;
    if(start != end){
        update(node * 2 , start, (start + end) / 2,idx, diff);
        update(node * 2 + 1 , (start + end) / 2 + 1, end, idx, diff);
    }
}

long long sum(int node, int start, int end, int left, int right){
    if(left > end || right < start)
        return 0;
    if(left <= start && end <= right){
        return tree[node];
    }
    return sum(node *2, start, (start + end) / 2, left, right) + sum(node *2 + 1, (start + end) / 2 + 1, end, left, right);
}


int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);

    int n, m, k;
    long long tmp;
    cin >> n >> m >> k;
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    v.resize(n,0);
    tree.resize(tree_size,0);
    
    for(int i = 0 ; i < n; i++){
        cin >> tmp;
        v[i] = tmp;
    }
    init(1, 0, n-1);

    for(int i = 0; i < m + k; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if(a == 1){
            b -= 1;
            long long diff = c - v[b];
            v[b] = c;
            update(1, 0, n-1, b, diff);
        }else{
            cout << sum(1, 0, n-1, b-1, c - 1) <<"\n";
        }
    }
}