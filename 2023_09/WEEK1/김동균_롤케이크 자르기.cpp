#include <string>
#include <vector>
#include<map>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int,int>order,younger;
    for(auto i : topping){
        order[i] ++;
    }
    
    for(auto i : topping){
        order[i]--;
        younger[i]++;
        if(order[i] == 0){
            order.erase(i);
        }
        if(order.size() == younger.size())answer++;
    }

    return answer;
}