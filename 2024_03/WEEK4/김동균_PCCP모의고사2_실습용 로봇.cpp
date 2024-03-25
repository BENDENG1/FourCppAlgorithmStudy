#include <string>
#include <vector>

using namespace std;

vector<int> solution(string command) {
    vector<int> answer(2,0);
    char dir[4] = {'U','R','D','L'};
    int dir_i = 0;
    for(char s : command){
        if(s=='G'){
           if (dir[dir_i] == 'U')
                answer[1] += 1;
            else if (dir[dir_i] == 'L')
                answer[0] -= 1;
            else if (dir[dir_i] == 'D')
                answer[1] -= 1;
            else
                answer[0] += 1;
        }else if(s == 'B'){
             if (dir[dir_i] == 'U')
                answer[1] -= 1;
            else if (dir[dir_i] == 'L')
                answer[0] += 1;
            else if (dir[dir_i] == 'D')
                answer[1] += 1;
            else
                answer[0] -= 1;
        }else{
            if(s=='R'){
                if(dir_i<3){
                    dir_i +=1;
                }else{
                    dir_i = 0;
                }
            }
            else{
                if(dir_i>0){
                    dir_i -= 1;
                }else{
                    dir_i = 3;
                }
            }
        }
    }
    return answer;
}