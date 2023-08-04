#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool prime(long long n) { // 소수로 변환
    if(n < 2) return false;
        
    for(int i=2; i<=sqrt(n); ++i) {
        if(n % i == 0) return false;
    }
    
    return true;
}

string convert_num(int n, int k) { // k진수로 변환
    string ret = "";
    
    while(n) {
        ret += to_string(n % k);
        n /= k;
    }
    
    return string(ret.rbegin(), ret.rend());
}


int solution(int n, int k) {
    int answer = 0;
    string s_num = convert_num(n, k);
    string tmp = "";
    
    for(int i = 0; i < s_num.size(); i++){ // 0을 기준으로 숫자를 짤라서 넣은다음 그 숫자가 소수인지 판별
        if(s_num[i] == '0' && !tmp.empty()){
            long long n = stoll(tmp);
            if(prime(n))
                answer++;
            tmp = "";
        }
        else{
            tmp += s_num[i];
        }
    }
    if(!tmp.empty()){
        long long n = stoll(tmp);
        if(prime(n))
            answer++;
    }
    return answer;
}