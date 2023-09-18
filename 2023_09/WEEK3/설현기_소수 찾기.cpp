#include <string>
#include <vector>
#include <set>
using namespace std;

vector <char> v; 
vector <bool> check; 
set <int> se;

bool isPrime(int num){
    if(num == 0 || num == 1)
        return false;;
    
    for(int i = 2; i < num; i++) {
        if(num % i == 0) 
            return false;
    }
    
    return true;
}

void dfs(int level, string s){
    if(level >= 1)
        if(isPrime(stoi(s)))
            se.insert(stoi(s));
    
    for(int i = 0; i < v.size(); i++){
        if(check[i] == true)
            continue;
        check[i] = true;
        dfs(level + 1, s + v[i]);
        check[i] = false;
    }
}

int solution(string numbers) {
    
    for(int i = 0; i < numbers.size(); i++) 
        v.push_back(numbers[i]);    
    
    check.resize(v.size(), false); 
    dfs(0, "");
    
    return se.size();
}