/*
유전법칙

RR RR-> RR
rr rr -> rr
Rr Rr -> RR Rr rR rr

4개의 후손을 남김 / 잡종은 RR Rr rR rr 순서 고정 / 우성 열성은 그대로
걍 자가수분 하는거지

n번째는 4^(n-1)이 되는건데

여기서 그 전 4^(n-2) 을 나누는데 0이면 무조건 RR / 3이상이면 무조건 rr

3,6이라면 나머지는 
4나머지
1 -> RR
2 -> Rr
3 -> Rr
0 -> rr

4^ 16 -> 2 ^ 32 단순 계산은 x

몫과 나머지가 중요한 문제인듯
*/

#include <string>
#include <vector>

using namespace std;

string comb[4] = {"rr","RR","Rr","Rr"};

string calculate(int n, int p){
    if(n == 1)
        return "Rr";
    if(n == 2)
        return comb[p%4];
    string parent = calculate(n-1, (p-1)/4 + 1);
    if(parent == "RR")
        return "RR";
    else if(parent == "rr")
        return "rr";
    else{
        return comb[p % 4];
    }    
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    
    for(int i = 0 ; i < queries.size();i++){
        string bean = calculate(queries[i][0],queries[i][1]);
        answer.push_back(bean);
    }
    return answer;
}