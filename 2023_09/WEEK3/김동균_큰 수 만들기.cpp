#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
	string answer;
	int max=0;
	int cnt=0;
	while(cnt<number.size()-k){
		int temp=max; 
		for(int i=max; i<=k+cnt; i++){
			if(number[i]>number[temp]){
				temp=i;
			}
		}
		answer+=number[temp];
		max=temp+1;
		cnt++;
	}
	return answer;
}
