#include <string>
#include <vector>

using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<int> solution(string command) {
    vector<int> answer;
    int x = 0, y = 0, idx = 0;
    
    for(char s : command){
        if(s == 'G'){
            x += dx[idx];
            y += dy[idx];
        }
        else if(s == 'R'){
            idx++;
            idx %= 4;
        }
        else if(s == 'L'){
            idx--;
            if(idx < 0) idx = 3;
        }
        else{
            x -= dx[idx];
            y -= dy[idx];
        }
    }
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}