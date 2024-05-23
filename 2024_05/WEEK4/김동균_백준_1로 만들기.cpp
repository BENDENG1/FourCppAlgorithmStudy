#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
    int* DP_Array = new int[1000000];
    int value;

    cin >> value;

    DP_Array[0] = DP_Array[1] = 0;

    for (int i = 2; i <= value; i++) {
        DP_Array[i] = DP_Array[i - 1] + 1; // 연산 -1의 경우

        if (i % 2 == 0) { // 연산 /2 의 경우
            DP_Array[i]=min(DP_Array[i], DP_Array[i / 2] + 1);
        }

        if (i % 3 == 0) { // 연산 /3의 경우
            DP_Array[i]=min(DP_Array[i], DP_Array[i / 3] + 1);
        }
    }
    cout << DP_Array[value] << endl;
    delete DP_Array;

}