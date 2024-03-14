#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int lcd(int a,int b,int gcd){
    return a * b / gcd;
}
long long solution(vector<int> weights) {
    long long answer = 0;
    map<int, int> weights_list;

    for (auto t : weights) {
        weights_list[t]++;
    }

    for (auto it1 = weights_list.begin(); it1 != weights_list.end(); it1++) {
        for(int f=0; f<it1->second-1; f++)
            for(int s=f+1; s<it1->second; s++)
                answer++;//같은 몸무게인 사람이 여러명일 때 그 사람들끼리의 쌍의 수
        
        for (auto it2 = next(it1); it2 != weights_list.end(); it2++) {
            int g = __gcd(it1->first, it2->first); // 두 키값의 최대공약수 구하기
            int l = lcd(it1->first,it2->first,g);
            if(l==it2->first){
                l *=2;
            }
            if(l/min(it1->first,it2->first)<5){
                answer += it1->second*it2->second;
            }
        }
    }
    return answer;
}