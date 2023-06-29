#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    int z_cnt = 0;
    int cnt = 0;
    while(s != "1"){
        string tmp = "";
        cnt++;
        for(char c : s){
            if(c == '1'){
                tmp += c;
            }
            else{
                z_cnt++;
            }
        }
        int X = tmp.size();
        s = "";
        while(X > 0)
        {
            s += to_string(X % 2);
            X /= 2;
        }
    }
    answer[0] = cnt;
    answer[1] = z_cnt;
    return answer;
}