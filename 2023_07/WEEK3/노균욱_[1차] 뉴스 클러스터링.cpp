/*
대문자와 소문자의 차이는 무시한다 -> 올 소문자로 

문자가 아니라면 문자 두개의 쌍은 취급하지 않음 (공백 포함)
근데 지우면 되는게 아님 그냥 취급을 안하는거지
체크를 할때 만약 소문자가 아니라면 -> 없앤다. 이런 느낌으로
map에다가 있다면 넣고 아니라면 지우고 이러면 되지 않을까?

*/
#include <string>
#include <iostream>
#include <map>
#include <cctype>

using namespace std;

string spellConvert(string s); //대소문자 구분이 없으니 일단 소문자로 다 변환


int solution(string str1, string str2) {
    int interSize = 0; // 교집합
    int unionSize = 0; // 합집합
    string tmp ="";
    map<string, int> m;
    
    str1 = spellConvert(str1);
    str2 = spellConvert(str2);
    
    for(int i = 0 ;i < str1.length() - 1;i++){
        if(isalpha(str1[i]) != 0 && isalpha(str1[i + 1]) != 0){
            tmp = str1[i];
            tmp +=str1[i+ 1];
            if(m.find(tmp) == m.end()){
                m.insert(make_pair(tmp,2));
                unionSize++;
            }
            else{
                m[tmp]++;
                unionSize++;
            }
        }
    }
    
    //여기 map에선 비교대상이기 때문에 만약에 같다면 interSize++ (교집합 갯수)
    //다르다면 unionSize++을 진행함
    for(int i = 0 ;i < str2.length() - 1;i++){
        if(isalpha(str2[i]) != 0 && isalpha(str2[i + 1]) != 0){
            tmp = str2[i];
            tmp +=str2[i+ 1];
            if(m.find(tmp) == m.end()){
                m.insert(make_pair(tmp,1));
                unionSize++;
            }else{
                if(m[tmp] >= 2){
                    interSize++;
                    m[tmp] --;
                }else{
                    unionSize++;
                }
            }
        }
    }
    
    if(unionSize == 0)
        return 65536;
    double size = (double) interSize / (double) unionSize;
    return size * 65536;
}

string spellConvert(string s){
    for(int i =0; i < s.length();i++){
        s[i] = tolower(s[i]);
    }
    return s;
}
