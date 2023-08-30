#include <string>
#include <vector>
#include <map>
using namespace std;
int count = 1;
vector<string> apb = {"A", "E", "I", "O", "U"};
map<string, int> m;
void dfs(string w){
    if(w.length() > 5) return;
    m[w] = count++;
    for(auto s : apb)
        dfs(w + s);
}

int solution(string word) {
    int answer = 0;
    
    for(auto s : apb)
        dfs(s);
    
    answer = m[word];
    return answer;
}