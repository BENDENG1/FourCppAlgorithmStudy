#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
int ft_atoi(char c);

string solution(string s) {
    string answer = "";
    int ft_max = -2147483647;
    int ft_min = 2147483647;
    istringstream iss(s);
    string token;
    
    
    while(getline(iss,token, ' ')){
        int num = stoi(token);
        if(ft_max < num)
            ft_max = num;
        if(ft_min > num)
            ft_min = num;
    }
    
    answer += to_string(ft_min);
    answer +=" ";
    answer += to_string(ft_max);
    
    
    return answer;
}