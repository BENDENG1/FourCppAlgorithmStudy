#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> tmp;
    if(cacheSize == 0){
        return 5 * cities.size();
    }
    for(int i = 0; i < cities.size(); i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    }
    for(int i = 0; i < cities.size(); i++){
        bool flag = false;
        for(int j = 0; j < tmp.size(); j++){
            if(tmp[j] == cities[i]){
                flag = true;
                answer++;
                tmp.erase(tmp.begin() + j);
                tmp.push_back(cities[i]);
                break;
            }
        }
        if(!flag){
            answer += 5;
            if(tmp.size() == cacheSize){
                tmp.erase(tmp.begin());
                tmp.push_back(cities[i]);
            }
            else{
                tmp.push_back(cities[i]);
            }
        }
    }
    return answer;
}