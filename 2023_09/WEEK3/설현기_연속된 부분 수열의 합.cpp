#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, 0);
    int lp = 0;
    int rp = 0;
    int sum = sequence[lp];
    int cnt = sequence.size();
    
    while(rp < sequence.size() && lp <= rp){
        if(sum < k){
            if(rp == sequence.size() - 1)
                break;
            sum += sequence[++rp];
        }
        else if(sum > k){
            sum -= sequence[lp++];
        }
        else{
            if(rp - lp < cnt){
                cnt = rp - lp;
                answer[0] = lp;
                answer[1] = rp;
            }
            if(rp != sequence.size() - 1)
                sum += sequence[++rp];
            else
                sum -= sequence[lp++];
        }
    }
    return answer;
}
// 1, 1, 1, 2, 3, 4, 5