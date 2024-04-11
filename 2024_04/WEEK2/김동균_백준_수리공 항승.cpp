//아무튼 간에 테이프로 시작지점부터 마크하기
//(단0.5뺴서)
// 다음 누수 지점이 안닿았으면 새로붙이기
//벡터로 선언하여 sort를 사용해서 정렬하기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void) {
    cin.tie(NULL);//입출력 동시
    ios_base::sync_with_stdio(false);//C++와 C언어의 동기화를 막는대신 시간을 절약한다.
    vector<float> Pipe;
    int N, L;
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        Pipe.push_back(temp);
    }
    sort(Pipe.begin(), Pipe.end());
    float start = Pipe.at(0) - 0.5;
    float end = start + L;
    int answer(1);//첫장은 붙이니까 자연수니까 1이상임
    for (int i = 0; i < N; i++) {
        if (Pipe[i] > end)
        {
            start = Pipe[i] - 0.5;
            end = start + L;
            answer++;
        }
    }
    cout << answer;
}