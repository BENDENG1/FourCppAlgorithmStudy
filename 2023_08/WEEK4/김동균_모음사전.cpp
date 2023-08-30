#include <string>
#include <vector>

using namespace std;
int count=0;
vector<string> ws={"A","E","I","O","U"};
void dfs(string start, string target, int &a){
    if(start==target){
        a=count;
    }
    if(start.size()<=5){
        count++;
        for(int i=0; i<ws.size(); i++){
            dfs(start+ws[i],target,a);
        }    
    }
}
int solution(string word) {
    int answer = 0;
    
    dfs("", word, answer);
    
    return answer;
}