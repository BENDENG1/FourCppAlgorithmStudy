#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    
    for(int i = 0; i < number.size(); i++){
        m[want[i]] = number[i];
    }
    for(int i = 0; i < discount.size() - 9; i++){
        map<string, int> m2;
        for(int j = i; j < i + 10; j++){
            m2[discount[j]] += 1;
        }
        if(m == m2)
            answer++;
    }
    return answer;
}