#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long calc(long long a, long long b, char c){
    if(c == '+') return a + b;
    else if(c == '-') return a - b;
    else if(c == '*') return a * b;
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num; 
    vector<char> op; 

    string temp = "";
    for(int i = 0; i < expression.size(); i++){
        if('0' <= expression[i] && expression[i] <= '9'){
            temp += expression[i];
        }
        else{
            num.push_back(stoll(temp));
            op.push_back(expression[i]);
            temp = "";
        }
    }
    if(temp != "") num.push_back(stoll(temp));

    char oplist[3] = {'+', '-', '*'};
    sort(oplist, oplist + 3);

    do{
        vector<long long> num_temp = num;
        vector<char> op_temp = op;
        for(int i = 0; i < 3; i++){ 
            for(int j = 0; j < op_temp.size(); j++){ 
                if(oplist[i] == op_temp[j]){
                    num_temp[j] = calc(num_temp[j], num_temp[j + 1], op_temp[j]);
                    num_temp.erase(num_temp.begin() + j + 1);
                    op_temp.erase(op_temp.begin() + j);
                    j--;
                }
            }
        }
        answer = max(answer, abs(num_temp[0]));
    }while(next_permutation(oplist, oplist + 3));

    return answer;
}