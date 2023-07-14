#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    map<int, int> m;
    for(int i = 1; i <= elements.size(); i++){
       for(int j = 1; j <= elements.size(); j++){
           int sum = 0;
           for(int k = 1; k <= i; k++){
               sum += elements[k-1];
           }
           m[sum]++;
           int tmp = elements.front();
           elements.push_back(tmp);
           elements.erase(elements.begin());
       }
    }
    answer = m.size();
    return answer;
}