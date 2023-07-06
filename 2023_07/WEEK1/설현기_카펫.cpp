// 타일의 갯수 합은 넓이로 생각하고, 세로의 경우 최소 3x3으로 시작해야하기때문에 3으로 시작, 
// 구한 넓이가 세로에 딱 나누어 떨어지면 가로길이를 구하고 둘레 타일의 갯수가 brown의 수와 같은지 확인한다. 
// 둘레 * 2에서 4를 빼는 이유는 사각형의 끝이 각각 겹치기 때문 같을경우 가로와 세로를 저장하고 break, 아닐 경우 세로를 +1하여 다시 반복한다.
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2, 0);
    int area = brown + yellow; 
    int height = 3; 
    
    while(true){
        if(area % height == 0){
            int width = area / height; 
            if((width + height) * 2 - 4 == brown){ 
                answer[0] = width;
                answer[1] = height;
                break;
            }
        }
        height++; 
    }
    return answer;
}