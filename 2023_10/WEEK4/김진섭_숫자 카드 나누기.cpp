//문제풀이: https://githubseob.tistory.com/360

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getGCD(int num1, int num2) {
    int num3(0);
    while (num2 > 0) {
        num3 = num1 % num2;
        num1 = num2;
        num2 = num3;
    }
    return num1;
}

int getNum(vector<int>A, vector<int>B) {
    int num(0);
    if (A.size() == 1) num = A[0];
    else num = getGCD(A[0], A[1]);

    for (int idx = 2; idx < A.size(); ++idx) num = getGCD(num, A[idx]);

    bool canDiv(false);
    for (int idx = 0; idx < B.size(); ++idx) {
        if (B[idx] % num == 0) {
            canDiv = true;
            break;
        }
    }

    if (canDiv == false) return num;
    else return 0;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer(0);

    answer = max(getNum(arrayA, arrayB), getNum(arrayB, arrayA));

    return answer;
}