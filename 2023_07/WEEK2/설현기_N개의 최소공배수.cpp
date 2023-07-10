/* 두 수의 최소공배수는 두 수의 곱 / 두 수의 최대공약수이다. 
벡터 맨 앞 2개의 수의 최소공배수를 구하고 그 수와 다음 인덱스의 수의 
최소공배수를 구하는 방식으로 반복한다. */
#include <string>
#include <vector>

using namespace std;
int gcd(int a, int b){
    int c = 0;
    while(true){
        c = a % b;
        if(c == 0){
            break;
        }
        a = b;
        b = c;
    }
    return b;
}
int lcm(int a, int b){
    return a * b / gcd(a, b);
}
int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i = 1; i < arr.size(); i++){
        answer = lcm(answer, arr[i]);
    }
    
    return answer;
}