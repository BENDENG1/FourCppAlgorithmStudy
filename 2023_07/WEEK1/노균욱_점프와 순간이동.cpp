/*
문득 생각을 해봤는데 2의 n제곱에 대해서 합을 생각해보면 되지 않을까?

라고 생각하고 노트를 펴 검산을 해보니 맞다.
*/

#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    int i = 1;
    int sum = 0;
    
    while (i < n)
        i *= 2; // 5000 이면 8192까지 가는거임
    
    while (sum != n){
        if(sum + i <= n){
            sum += i; 
            ans++;
        }
        if(sum == n)
            break;
        i /= 2; 
    }
    return ans;
}