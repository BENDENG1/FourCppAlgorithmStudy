/*
무조건 오름차순으로 정리를 함
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, tmp, start, end;
    vector<int> v;
    vector<int> ansV;

    cin >> n >> k;

    v.push_back(0);
    for(int i = 0 ; i < n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    for(int i = 0 ; i < k; i++){
        cin >> start >> end >> tmp;
        ansV.clear();
        ansV.insert(ansV.end(), v.begin() + start, v.begin() + end + 1);
        sort(ansV.begin(), ansV.end());
        cout << ansV[tmp - 1]<< "\n";
    }
}
