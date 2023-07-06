#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> people, int limit) {
  int sum(0);
  int answer(0);
  sort(people.begin(),people.end());

  int i = 0;
  int j = people.size()-1;
  while(i<=j){
    sum = limit -people[j];
    if(sum>=people[i]){
      i++;
    }
    j--;
    answer++;
  }
    return answer;
}