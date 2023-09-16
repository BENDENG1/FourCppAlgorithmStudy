#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    string str1=to_string(a)+to_string(b);
    string str2=to_string(b)+to_string(a);
    return str1>str2;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(),numbers.end(),compare);
    
    for(int i=0;i<numbers.size();i++){
        answer+=to_string(numbers[i]);
    }
    if(numbers[0]==0) answer="0";
    
    return answer;
}