#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int EratosPrime(const int& T) {
    vector<bool> vcheck(2 * T + 1, true);  // T보다 크거나 같은 소수를 찾아야 하므로 벡터의 크기를 2*T+1로 설정
    vcheck[1] = false;
    for (int i = 2; i * i <= 2 * T; i++) {  // i가 2부터 시작해야 함
        if (!vcheck[i]) continue;
        for (int j = i * i; j <= 2 * T; j += i)  // j를 i*i부터 시작해야 함
            vcheck[j] = false;
    }
    int count = 0;
    for (int i = T + 1; i <= 2 * T; i++) {
        if (vcheck[i]) count++;
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T != 0) {  // T가 0이 아닐 때까지 반복해야 함
        cout << EratosPrime(T) << endl;
        cin >> T;
    }
    return 0;
}
//Erastos의 체를 사용한 소수 판별 알고리즘 