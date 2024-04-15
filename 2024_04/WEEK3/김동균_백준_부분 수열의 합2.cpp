//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false); // C++ 스타일의 빠른 입출력을 위해
//    cin.tie(nullptr);
//
//    long long N, S, a;
//    cin >> N >> S;
//    vector<vector<long long>> D(2, vector<long long>(8000001, 0)); // 2D 벡터 사용
//
//    for (int i = 0; i < N; i++) {
//        cin >> a;
//        for (int j = 0; j <= 8000000; j++) {
//            D[i % 2][j] = D[(i + 1) % 2][j];
//            if (0 <= j - a && j - a <= 8000000) D[i % 2][j] += D[(i + 1) % 2][j - a];
//            if (j - 4000000 == a) D[i % 2][j]++;
//        }
//    }
//
//    cout << D[(N - 1) % 2][S + 4000000];
//
//    return 0;
//}
#include <map>
#include <iostream>
#include <vector>
using namespace std;


size_t sequenceSize, targetSum, sequence[41], totalWays;
map<int, size_t> sumCounts;

void solve(int currentIndex, int currentSum, int end) {
    if (currentIndex == end) {
        if (end == sequenceSize) totalWays += sumCounts[targetSum - currentSum];
        else sumCounts[currentSum]++;
        return;
    }
    solve(currentIndex + 1, currentSum, end);
    solve(currentIndex + 1, currentSum + sequence[currentIndex], end);
}

int main() {
    cin >> sequenceSize >> targetSum;
    for (int i = 0; i < sequenceSize; i++)
        cin >> sequence[i];
    solve(0, 0, sequenceSize / 2);
    solve(sequenceSize / 2, 0, sequenceSize);
    if (!targetSum) totalWays--;
    cout << totalWays;
}
