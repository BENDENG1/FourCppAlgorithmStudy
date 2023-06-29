#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int k = 1; k <= n; k++) {
        // 등차수열의 합 공식 k*m + k*(k - 1)/2 = n
        // km + k^2-k/2 = n
        // km=n-(k(k-1)/2)
        int m = ((n - (k * (k - 1)) / 2) / k);
        if (m > 0 && n == k * m + (k * (k - 1)) / 2) {
            answer++;
        }
    }
    return answer;
}


