/*
튜플

문제를 풀때 중요한 두가지
1. 문자열 처리에 대해서 조심히 처리
2. 빈도수가 높은것이 결국 맨앞이다.

2번에 대해서 고려를 한다면 vector<pair<int,int>>이런식으로 진행을 해서 하면 되지 않을까 싶다.
첫번째는 숫자, 두번째는 빈도(cnt)로 하면 될듯 싶다.
그래서 나중에 cnt를 기준으로 역순 정렬을 한다. 그리고 리턴

근데 여기서 그냥 map을 사용하면 더 편하지 않을까 싶다.

map을 하고 다음에 vector에 대해서 추가를 해 두번째 원소(.second)에 대해서 정렬을 하고 
answer에 대해 push_back을 하면 끝.

*/
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int>& a, pair<int,int>& b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    int num = 0;
    map<int,int> m;
    
    for(int i = 1; i < s.length();i++){
        //숫자인 경우
        if('0'<=s[i] && s[i] <= '9'){
            int num = 0;
            //두자릿수 이상 숫자 처리 
            while('0'<=s[i] && s[i] <= '9'){
                num *= 10;
                num += (s[i] - '0');
                i++;
            }
            if(m.find(num) == m.end()){
                m[num] = 1;
            }else{
                m[num]++;
            }
        }
    }
    vector<pair<int,int>> v (m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    
    for(int i =0; i < v.size();i++){
        answer.push_back(v[i].first);
    }
    return answer;
}