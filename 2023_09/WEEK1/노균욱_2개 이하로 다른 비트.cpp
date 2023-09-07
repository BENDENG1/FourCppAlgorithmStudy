/*
2개 이하로 다른 비트

x보다 크고 x와 비트가 1~2개 다른 수들중에서 가장 작은수


만약 짝수라면? 그냥 맨 뒤에 + 1을 하고 return 왜냐? 더 커야해서

음 그냥 0이 나올때까지에 대해서 계속 비트를 밀어(*2를한다) 근데 0이 나온다? -> break
그리고 break된 bit 2로 나눠
1010111 일때 bit는 그럼 8이 되는거지
1010111 + 1000을하면? -> 10101111이 되어서 가장 낮은 x보다 큰 수가 나옴.

만약 11111이라면? bit가 32가 되고 11111 + 10000 -> 101111이 되어서 만족하는거임
*/
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    
    for(int i = 0; i < numbers.size();i++){
        if(numbers[i] % 2 == 0)
            answer.push_back(numbers[i] + 1);
        else{
            long long bit = 1;
            while(1){
                if((numbers[i] & bit) == 0)
                    break;
                bit *= 2;
            }
            bit /= 2;
            answer.push_back(numbers[i] + bit);
        }
    }
    return answer;
}


/*
일단은 2진수로 변환을 진행하며

x보다 크고 x와 비트가 1~2개 다른 수들 중에서 제일 작은 수를 추출하는 것

9 -> 1001 -> 1011이 되는 것
11 -> 1011 -> 1101이 되는것

음 짝수는 그냥 +1하면 끝이고 

홀수는 0이 작은 순서대로 하나라도 있으면 거기에다가 1넣으면 되고
없으면 111 -> 1011이 정답 즉,이렇게 되기 위해서 가장큰 1의 실제 숫자의 나누기 2를 더해야함
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i = 0; i < numbers.size();i++){
        if(numbers[i] % 2 == 0){
            answer.push_back(numbers[i] + 1);
            continue;
        }
        long long bit = 1;
        while((numbers[i] & bit) != 0){
            bit *= 2;
        }
        answer.push_back(numbers[i] + bit/2);
    } 
    return answer;
}



