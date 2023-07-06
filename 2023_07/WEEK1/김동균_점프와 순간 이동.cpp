#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while(n!=1){
    if(n%2!=0)
      ans++;
    n /=2;
  }
    ans++;
    return ans;
}