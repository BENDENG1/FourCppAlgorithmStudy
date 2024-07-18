#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool digit[10];
int main() {
  int K, cnt = 0;
  string N;
  cin >> N >> K;
  if (K == 10)
    cout << "1023456789";
  else if (K == 9)
    cout << "102345678";
  else {
    while (cnt != K) {
      fill_n(digit, 10, false);
      cnt = 0;
      N = to_string(stoi(N) + 1);
      for (int i = 0; i < N.length(); i++)
        digit[N[i] - '0'] = true;
      for (int i = 0; i < 10; i++)
        if (digit[i])
          cnt++;
    }
    cout << N;
  }
}

//7월 16일