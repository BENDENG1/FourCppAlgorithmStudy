#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& li, int M) {
    int s = 1;
    int e = *max_element(li.begin(), li.end());
    int ans = 0;
    while (s <= e) {
        int m = (s + e) / 2;
        int t = 0;
        for (int n : li) {
            if (n > m) {
                t += m;
            } else {
                t += n;
            }
        }
        if (t <= M) {
            s = m + 1;
            ans = m;
        } else {
            e = m - 1;
        }
    }
    return ans;
}

int main() {
    int N, M;
    cin >> N;
    vector<int> li(N);
    for (int i = 0; i < N; i++) {
        cin >> li[i];
    }
    cin >> M;
    cout << binarySearch(li, M) << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int N, temp, M;
    int mod = 0;
    int answer = 0;
    cin >> N;
    vector<int> Array;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        Array.push_back(temp);
    }
    cin >> M;
    sort(Array.begin(), Array.end(),less<int>());
    int Max = accumulate(Array.begin(), Array.end(),0);
    if (M >= Max) {
        cout << Array.back();
    }
    else {
        int Size = Array.size();
        for (int i = 0; i < Size; i++) {
            if (Array[i] <= (M / Size)) {
                M -= Array[i];
                Size--;
            }
            else {
                cout << (M/(Size));
                break;
            }
        }
    }
    return 0;
}


