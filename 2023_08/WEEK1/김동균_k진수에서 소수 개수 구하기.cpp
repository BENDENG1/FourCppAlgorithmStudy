#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(long long num) {
    if (num <= 1) return false;
    for(int i=2;i<(int)sqrt(num)+1;i++){
        if(num%i==0)
            return false;
    }
    return true;   
}

string trans(long long a, long long b)
{
    string s_num = "";

    while (a > 0)
    {
        int remainder = a % b;
        s_num = to_string(remainder) + s_num;
        a = a / b;
    }

    return s_num;
}

int solution(int n, int k)
{
    int answer = 0;
    string s_num = trans(n, k);

    string tmp = "";

    for (int i = 0; i < s_num.size(); i++)
    { // 0을 기준으로 숫자를 자르고, 해당 숫자가 소수인지 판별
        if (s_num[i] == '0' && !tmp.empty())
        {
            long long num = stoll(tmp); // stoll을 사용하여 문자열을 long long 타입으로 변환

            // 소수 판별은 isPrime 함수로 직접 수행
            if (isPrime(num))
                answer++;
            tmp = "";
        }
        else
        {
            tmp += s_num[i];
        }
    }
    if (!tmp.empty())
    {
        long long num = stoll(tmp); // stoll을 사용하여 문자열을 long long 타입으로 변환

        if (isPrime(num))
            answer++;
    }
    return answer;
}
