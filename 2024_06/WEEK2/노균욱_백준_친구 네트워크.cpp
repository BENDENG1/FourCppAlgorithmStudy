/*
친구 네트워크

그룹화 시키는 문제가 요즘 많이 나오는듯

map으로 parent 찾아서 ++ 하면 되고 parent의 count 를 계속 갱신
*/
#include <iostream>
#include <map>

using namespace std;

struct Group{
    string parent;
    int count;
};
map<string, Group> m;

string findParent(string s){
    if(m[s].parent == s){
        return s;
    }else{
        return m[s].parent = findParent(m[s].parent);
    }
}

void makeGroup(string first, string second){
    string s1 = findParent(first);
    string s2 = findParent(second);

    if(s1 != s2){
        m[s2] = {s1,m[s2].count};
        m[s1] = {s1,m[s1].count + m[s2].count};
    }
}


int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);

    int t,f;

    cin >>t;
    for(int i =0 ; i < t; i++){
        cin >> f;
        m.clear();
        for(int j = 0 ; j < f; j++){
            string first, second;
            cin >> first >> second;

            if(m.count(first) == 0){
                m[first] = {first,1};
            }
            if(m.count(second) == 0){
                m[second] = {second,1};
            }
            makeGroup(first,second);
            cout << m[findParent(first)].count << "\n";
        } 
    }
}