#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long int sum1 = 0;
    long long int sum2 = 0;
    long long int cnt = 0;
    int idx1 = 0;
    int idx2 = 0;
    int n = queue1.size();
    
    for(int i = 0; i < n; i++){
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    
    while(sum1 != sum2){
        if(sum1 > sum2){
            queue2.push_back(queue1[idx1]);
            sum1 -= queue1[idx1];
            sum2 += queue1[idx1];
            cnt++;
            idx1++;
        }
        else if (sum2 > sum1){
            queue1.push_back(queue2[idx2]);
            sum2 -= queue2[idx2];
            sum1 += queue2[idx2];
            cnt++;
            idx2++;
        }
        if(cnt == n * 4){
            return -1;
        }
    }
    return cnt;
}