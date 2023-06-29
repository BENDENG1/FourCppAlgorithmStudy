#include <cctype>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
#include <sstream>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string temp="";
    int temp2;
    int count1(0);
    int count2(0);
    int num;

     while(s.size()!=1){
        for(int i=0; i<s.size();i++){
            if(s[i]=='0'){
                count1++;
            }
            else {
                temp += s[i];
            }
        }
        bitset<32> b(temp.size());
        s = b.to_string();
        s = s.substr(s.find_first_not_of('0'));
        count2++;
        temp = ""; 
    }
    
    answer.push_back(count2);
    answer.push_back(count1);
      
    return answer;
}