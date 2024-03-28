#include <string>
#include <vector>

using namespace std;

string gen(int n, int p) {
    if(n == 1) 
        return "Rr";
    
    string parent = gen(n - 1, ((p - 1) / 4) + 1); // 부모 좌표 찾기
    
    if(parent == "RR" || parent == "rr")    return parent; // parent = RR or rr 이면 자식도 RR or rr
    
    // parent = Rr일 경우
    else if(p % 4 == 1) { 
        return "RR";
    }
    else if(p % 4 == 0) { 
        return "rr";
    }
    else 
        return "Rr";
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;

    for(auto query : queries) {
        answer.push_back(gen(query[0], query[1]));
    }
    
    return answer;
}