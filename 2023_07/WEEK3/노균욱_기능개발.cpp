/*
기능 개발

먼저 배포되어야하는 순서대로 작업의 진도가 적힌 progresses
각 작업의 개발속도가 적힌 speeds
각 배포마다 몇개의 기능이 배포되는지를 return

결국 먼저 끝냈더라도 앞에의 progresses가 끝나지 않으면 기다림

*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int done = 0; //어디까지 끝냈는지에 대한 index로 설정
    int progress = 0; //앞에 있는곳이 진행될때마다 뒤에 것에 대해 진행이 된것이 연속적인것을 저장
    
    while(1){
        for(int i = 0; i < speeds.size();i++){
            progresses[i] += speeds[i];
        }
        
        if(progresses[done] >= 100){
            while(progresses[done] >= 100 && done < progresses.size()){
                done++;
                progress++;
            }
            answer.push_back(progress);
            progress = 0; // 다시 0으로 초기화 해줌으러써 다른 작업이 완료될때 ++을 함.
        }
        
        if(done >= progresses.size())
            break;
    }
    
    return answer;
}