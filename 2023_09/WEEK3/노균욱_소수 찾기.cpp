/*
최근 스터디 풀이 
만들 수 있는 소수의 갯수 permutation사용 해야겠다.

011 -> 11 임 00013 -> 13 근데 그냥 맨앞 0을 지워버리고 set에 때려버리면?
*/
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

bool isPrime(int n);

int solution(string numbers) {
    int answer = 0;
    set <int>primeSet;
    
    sort(numbers.begin(),numbers.end());
    
    do{
        int num = 0;
        for(int i = 0; i < numbers.size();i++){
            num *= 10;
            num += numbers[i] - '0';
            if(isPrime(num)){
                primeSet.insert(num);
            }
        }
    }while(next_permutation(numbers.begin(),numbers.end()));
    
    return primeSet.size();
}


bool isPrime(int n) {
    if (n <= 1 || n == 4) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    for(int i = 2; i*i <=n;i++){
        if(n%i ==0)
            return false;
    }
    return true;
}

/*
과거 풀이 -> 진짜 더럽다;;
소수 찾기 길이 1~7
주어진 numbers의 모든 조합에 대해서 소수의 갯수를 찾는 문제.
주의 : 011 -> 11임

일단 우선적으로 짝수 x, 모든합의 3의배수x

모든 조합에 대해서 확인을 해봐야하는데..
이거는 algorithm헤더에 next_permutation이 있음

그렇게 벡터에 추가한 벡터에 대해서 중복을 지워주고 소수를 판별하면 됨.

*/
/*
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    
    vector<int> v;
    vector<int> permutation; //모든 조합들에 대한 백터
    
    for(int i = 0 ; i< numbers.length();i++){
        v.push_back((numbers[i] - '0'));
    }
    sort(v.begin(),v.end());
    
    do{
        int num = 0;
        for(int i = 0; i < v.size();i++){
            num *= 10;
            num += v[i];
            permutation.push_back(num);
        }
    }while(next_permutation(v.begin(),v.end())); //모든 조합에 대해서 진행
    
    sort(permutation.begin(),permutation.end()); //모든 조합들에 대해 정렬
    permutation.erase(unique(permutation.begin(),permutation.end()),permutation.end()); //중복 제거
    
    for(int i = 0; i < permutation.size();i++){
        int PrimeFlag = 1; //소수플래그
        if(permutation[i] < 2)
            continue; // 0혹은 1은 소수아님
        else if(permutation[i] == 2){
            answer++;
            continue;
        }
        for(int j = 2;j<=sqrt(permutation[i]);j++){
            if(permutation[i] % j == 0 || permutation[i] % 2 == 0){
                PrimeFlag = 0;
                break;
            }
        }
        if(PrimeFlag == 1){ //소수일때 ++
            answer++;
        }
    }
    return answer;
}

*/


