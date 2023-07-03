/*
숫자가 주어지면 그에 대한 피보나치 수를 구하는 간단한 문제이다.

이 문제는 아마 dp로 풀면 가장 간단하지 않을까 싶다.
처음에는 기본적으로 0,1이 존재하고 2이상이 입력되었을때 
문제의 예시처럼 f(2) = f(0) + f(1);이다.
즉, f(n) = f(n-1) + f(n-2)이다. 그냥 반복문 돌려~
개 억까 문제임 이거 수를 1234567을 나머지를 리턴하는건데 말이 애매해
*/
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    
    //초기 값 두개 push_back
    v.push_back(0);
    v.push_back(1);
    
    for(int i = 2; i <= n; i++){
        int sum = v[i-1] + v[i-2];
        sum %= 1234567;
        v.push_back(sum);
    }
    
    answer = v.back();
    return answer;
}