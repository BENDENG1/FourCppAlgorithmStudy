/* 1~n칸까지 가는 경우의 수를 각각 정의하기위해 벡터로 생성 후, 1칸과 2칸가는 경우의 수는 정의해놓은 다음
3부터 n까지 현재 인덱스-2 + 현재 인덱스-1를 더한 값을 정의하는 것을 반복했다.(문제에 나와있는 4칸의 경우,
처음 뛰기 이후 나머지는 3칸뛰거나 2칸을 뛰어야하기 때문에 3칸 경우의수 + 2칸 경우의수)*/
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<int> arr(2000, 0);
    arr[1] = 1; arr[2] = 2;
    for(int i = 3; i <= n; i++){
        arr[i] = (arr[i-2] + arr[i-1]) % 1234567;
    }
    answer = arr[n];
    return answer;
}
