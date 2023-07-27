#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> s1, s2;
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    for(int i = 0; i < str1.length(); i++){
        if(!isalpha(str1[i]) || !isalpha(str1[i+1]))
            continue;
        string tmp = "";
        tmp += str1[i];
        tmp += str1[i+1];
        s1.push_back(tmp);
    }
    
    for(int i = 0; i < str2.length(); i++){
        if(!isalpha(str2[i]) || !isalpha(str2[i+1]))
            continue;
        string tmp = "";
        tmp += str2[i];
        tmp += str2[i+1];
        s2.push_back(tmp);
    }
    
    int sumS = s1.size() + s2.size();
    int interS=0;
    
    for(int i = 0; i < s1.size(); i++){
        auto it = find(s2.begin(), s2.end(), s1[i]);
        if(it != s2.end()){
            interS++;
            s2.erase(it);
        }
    }
    sumS -= interS;
    
    if(sumS == 0)
        answer = 1 * 65536;
    else{
        double result = ((double) interS / (double) sumS) * 65536;
        answer = (int) result;
    }
    
    return answer;
}