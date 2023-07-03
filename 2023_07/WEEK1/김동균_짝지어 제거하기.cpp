#include <iostream>
#include<string>
#include<vector>

using namespace std;

int solution(string s)
{
    int answer = -1;
    vector <char> temp;
    temp.push_back(s[0]);
    for(int i=1;i<s.size();i++){
      if(s[i]==temp.back() && !temp.empty()){
        temp.pop_back();
    }
      else
        temp.push_back(s[i]);
    }
    return temp.empty();
}