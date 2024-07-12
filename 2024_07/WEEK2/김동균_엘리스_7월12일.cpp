#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N;
vector<int> Array;
set<int> Sums;

void dfs(int idx, int sum) {
    if (idx == Array.size()) {
        Sums.insert(sum);
        return;
    }

    dfs(idx + 1, sum);
    dfs(idx + 1, sum + Array[idx]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int Size = pow(2, N);
    Array.resize(Size);
    for (int i = 0; i < Size; ++i) {
        cin >> Array[i];
    }

    dfs(1, 0);

    vector<int> Answer;
    for (auto it = Sums.begin(); Answer.size() < N; ++it) {
        Answer.push_back(*it);
    }

    sort(Answer.begin(), Answer.end());
    for (int num : Answer) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
