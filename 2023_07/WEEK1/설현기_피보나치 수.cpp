#include <string>
#include <vector>

using namespace std;
/*int get_fibo(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    return get_fibo(n - 2) + get_fibo(n - 1);
}*/ // 재귀함수로 풀었다가 실패

int get_fibo(int n){
    int f[100001];
    f[0] = 0; f[1] = 1;
    
    for(int i = 2; i <= n; i++){
        f[i] = (f[i-2] % 1234567)+ (f[i-1] % 1234567);
    }
    return f[n] % 1234567;
}
int solution(int n) {
    int answer = get_fibo(n);
    
    return answer;
}