#include <iostream>
#include <algorithm>
using namespace std;


int result = 987654321;
int c = 0;

void solution(int *A,int *B,int H) {
    for (int i = 1; i <= H; i++) {
        A[H - i] += A[H - i + 1];
        B[i] += B[i - 1];
    }

    for (int i = 1; i <= H; i++) {
        if (A[i] + B[i] < result) {
            c = 1;
            result = A[i] + B[i];
        }
        else if (A[i] + B[i] == result) {
            c++;
        }
    }

    
}

int main() {
    int N, H;
    cin >> N >> H;
    int* ListA = nullptr;
    int* ListB = nullptr;
    ListA = new int[50000+ 1](); // 동적 할당 malloc은 초기화를 해주지않음
    ListB = new int[50000+ 1](); // 동적 할당시 사실 N/2+1과 H를 비교해서 더 큰걸 하는게 가장 메모리 활용이 좋지만 그건좀 

    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (i % 2 == 0) {
            ListA[a]++;
        }
        else {
            ListB[H - a + 1]++;
        }
    }

    solution(ListA,ListB,H);
    cout << result << " " << c;
    delete[] ListA; // 동적 할당 해제
    delete[] ListB; // 동적 할당 해제

}