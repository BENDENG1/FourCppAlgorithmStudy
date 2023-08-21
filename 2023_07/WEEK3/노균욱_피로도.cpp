/*
k진수에서 소수 개수 구하기

중간에 있을때는 양옆의 0일때 

그냥 마음 편하게 앞뒤에 0을 집어 넣으면 마음이 편함
그러면 무조건 양옆이 0인 케이스밖에 없음 끝.
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isPrime(unsigned long long n)
{
    if (n <= 3)
        return n > 1;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (long long i = 5; i * i <= n; i++)
        if(n % i == 0)
            return false;
        
    return true;
}


int solution(int n, int k) {
    int answer = 0;
    int location = 1;
    unsigned long long num = 0;
    
    vector<int> v;
    
    //이런식이면 15면 210이 되야함
    while(n > 0){
        v.insert(v.begin(),n % k);
        n /= k;
    }
    
    //초반과 끝에 0을 넣어줌으로써 무조건 양옆에 0일경우에만 진행을 하는것으로 진행
    //굳이 split할 필요없이 0이 들어오면 무시하는 방향으로 그리고 양옆에 0이 꼭 있게 되는 상황으로 만들어줌
    v.insert(v.begin(),0);
    v.push_back(0);
    
    for(int i = 0; i < v.size();i++){
        if(v[i] == 0){
            if(isPrime(num))
                answer++;
            num = 0;
        }
        else{
            num *= 10;
            num += v[i];
        }
    }
    return answer;
}