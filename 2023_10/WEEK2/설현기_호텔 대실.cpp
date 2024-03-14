#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[25][61];

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    for(int i = 0; i < book_time.size(); i++) {
        int sh = stoi(book_time[i][0].substr(0, 2));
        int sm = stoi(book_time[i][0].substr(3, 2));
        int eh = stoi(book_time[i][1].substr(0, 2));
        int em = stoi(book_time[i][1].substr(3, 2));
        em += 10;
        
        if(em > 59) {
            eh++;
            em -= 60;
        }
        
        for(int j = sh; j <= eh; j++) {
            for(int k = 0; k < 60; k++) {
                if(j == sh) {
                    if(k < sm) continue;
                }
                if(j == eh) {
                    if(k >= em) break;
                }
                arr[j][k]++;
            }
        }
    }
    
    for(int i = 0; i < 24; i++) {
        for(int j = 0; j < 60; j++) {
            if(arr[i][j] > answer)
                answer = arr[i][j];
        }
    }
    
    return answer;
}