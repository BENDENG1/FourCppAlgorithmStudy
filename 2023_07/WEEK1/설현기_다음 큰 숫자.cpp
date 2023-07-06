#include <string>
#include <vector>

using namespace std;
string get_binary(int n){
    string b_num = "";
    
    while(n > 0){
        b_num = to_string(n % 2) + b_num;
        n /= 2;
    }
    
    return b_num;
}
int get_count(string s){
    int cnt = 0;
    
    for(char c : s){
        if(c == '1')
            cnt++;
    }
    return cnt;
}
int solution(int n) {
    int answer = n+1;
    int cnt = get_count(get_binary(n));
    while(true){
        if(get_count(get_binary(answer)) == cnt)
            break;
        answer++;     
    }
    return answer;
}