//문제풀이: https://githubseob.tistory.com/242

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer(0), idx(0);

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for (idx = 0; idx < A.size(); ++idx)
        answer += A[idx] * B[idx];
    return answer;
}