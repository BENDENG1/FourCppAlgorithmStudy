/*
줄서는 방법

음.. 나누기랑 나머지에 대해서 컨트롤하면 되지 않을까?
전체를 하나씩 계산하라고 내는 문제는 아닌거 같고

4 10이면
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2 -> 여기까지 뒤에 세개는 3!임
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1 로 2 3 4 1이 되는거다.

4일때에 대해서 (1 2 3 4)
9 / 3! -> 1
9 % 3! -> 3 왜 9냐? 6이면 1 4 3 2가 되야하는데 1 0 은 아님 0 5가 되야함 즉, -1을 처음에 해주면 됨

1인덱스 접근
1 3 4 2가 되고
3 / 2! -> 1
3 % 2! -> 1

1인덱스 접근 
1 4 2 3이 되고
1 / 1! = 1
1 % 1! = 1이 되고

1인덱스 접근
1 2 3 4이 되고
0!은 1인데 이거는 그냥 남은거 emplace_back하면 되는거 아닌가?

2 3 4 1이 되는거지 최종으로 ㅇㅇ
*/
#include <string>
#include <vector>

using namespace std;

long long factorial(int n){
    long long num = 1;
    while(1 < n){
        num *= n--;
    }
    return num;
}

vector<int> solution(int n, long long k) {
    vector<int> answer,number;
    long long idx,num;
    
    
    for(int i = 1 ; i <= n; i++){
        number.emplace_back(i);
    }
    
    k--;
    
    while(k != 0){
        num = factorial(--n);
        idx = k / num;
        k %= num;
        answer.emplace_back(number[idx]);
        number.erase(number.begin() + idx);
    }
    
    //답이 3 5 1 2 4 이면 5에서 중단되고 1 2 4 를 순서대로 emplace_back함
    for(int i = 0 ; i < number.size();i++){
        answer.emplace_back(number[i]);
    }
    
    return answer;
}