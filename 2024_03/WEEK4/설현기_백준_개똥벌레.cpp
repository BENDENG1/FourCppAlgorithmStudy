#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n, h, tmp;
    int min_num = 200001, answer = 0;
    
    cin >> n >> h;
    
    vector<int> up, down;
    
    for(int i = 0; i < n; i++){
        cin >> tmp;
        if(i % 2 == 0){
            up.push_back(tmp); // 석순
        }
        else{
            down.push_back(h - tmp); // 종유석
        }
    }
    
    sort(down.begin(), down.end()); 
    sort(up.begin(), up.end());
    
    for(int j = 1; j <= h; j++){
        int cnt = up.size() - (lower_bound(up.begin(), up.end(), j) - up.begin());
        cnt += (lower_bound(down.begin(), down.end(), j) - down.begin());

        if(cnt < min_num){
            min_num = cnt;
            answer = 1;
        }
        else if(cnt == min_num){
            answer++;
        }
    }
    
    cout << min_num << " " << answer;
    return 0;
}