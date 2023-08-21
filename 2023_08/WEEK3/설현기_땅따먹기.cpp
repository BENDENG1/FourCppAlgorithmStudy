#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for(int i=1; i<land.size(); i++) { 
        for(int j=0; j<4; j++) { 
            int temp = -1; 
            for(int k=0; k<4; k++) { 
                if(k!=j) 
                    temp = max(temp, land[i-1][k]); 
            }
            land[i][j] += temp; 
        }
    }
    
    for(int i=0; i<4; i++) { 
        answer = max(answer, land[land.size()-1][i]);
    }
    return answer;
}