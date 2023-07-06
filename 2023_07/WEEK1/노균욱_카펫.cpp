/*
노란색과 갈색으로 색칠된 격자의 갯수 기억 but 크기는 기억 x

중앙은 노란색 테두리는 갈색

추측 1)
가로 변 새로 변을 x,y라고 치면

네변의 갈색의 합은 2x + 2y - 4로 구성이 된다.
brown + yellow 의 갯수합은 xy이다. -> 이를 통해 약수여야 함

약수는 기본적으로 숫자 n이라 치면 루트n까지만 구하면 다 구해짐 -> 시간 절약
*/
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int c_sum = brown + yellow; //두개 타일의 합
    int n = int(sqrt(c_sum)) + 1; // 36이라면 6까지만 체크하면 됨
    
    for(int y = 1; y < n ; y ++){
        int x = 1;
        while (1){
            if (brown == 2*x+2*y-4 && x*y == c_sum)
                //조건 가로길이는 세로길이와 같거나 새로길이보다 김 -> 나중에 xy추출하고 큰거를 앞으로 하면 됨
                return{x,y};
            if(x * y > c_sum)
                break;
            x++;
        }
    }
}