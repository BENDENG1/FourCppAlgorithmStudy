#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>


using namespace std;

map<string,int> m;

void dfs(string &order, int len, string tmp,int idx){
    if(tmp.length() == len){
        m[tmp] += 1;
        return;
    }
    
    for(int i =idx;i<order.length();i++){
        dfs(order,len,tmp + order[i],i+1);
    }
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i = 0; i < course.size(); i++){
        for(int j = 0 ; j < orders.size();j++){
            sort(orders[j].begin(),orders[j].end());
            string tmp = "";
            dfs(orders[j],course[i],tmp,0);
        }
        
        int turn = 0;
        for(auto iter : m){
            turn = turn < iter.second ? iter.second : turn;
        }
        
        for(auto iter : m){
            if(iter.second == turn && iter.second > 1)
                answer.push_back(iter.first);
        }
        m.clear();
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}