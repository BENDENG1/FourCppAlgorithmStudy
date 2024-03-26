/*
개똥벌레

동굴의 길이는 n, 높이 h 

첫번재 석순 그다음부터는 종유석,석순 번갈아서 나옴

위에가 3미터이면 -> 1,2만 됨
아래가 3미터 -> 4,5

파괴해야하는 장애물의 최솟값 / 그러한 구간의 수

시간초과.. 음 어떻ㄱ ㅔ시간을 줄일 수 없나?
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 500001

vector<int> up(500001,0);
vector<int> down(500001,0);


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n,h,height;
    int cnt = 0;
    int sum = MAX;

    cin >> n >> h;

    for(int i = 0 ; i < n; i++){
        cin >> height;
        if(i % 2 ==0)
            up[height - 1]++;
        else
            down[h - height]++;
    }

    for(int i = 1; i < h;i++){
        up[h - i - 1] += up[h - i];
        down[i] += down[i - 1];
    }
    //cout<<"\n\n";
    for(int i = 0; i < h; i++){
        //cout<<up[i]<<"   "<< down[i]<<"\n";
        if(up[i] + down[i] < sum){
            cnt = 1;
            sum = up[i] + down[i];
        }else if(up[i] + down[i] == sum)
            cnt++;
    }
    //cout<<"\n\n";

    cout << sum << " "<< cnt;
}

/*
vector<int> defense(500001,0);

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n,h,height;
    int cnt = 0;
    int sum = MAX;

    cin >> n >> h;


    //보나마나 얘가 문제임 -> up down으로 나눠서 dp 처럼 ++ 로 해줘서 하는게 나을듯
    for(int i = 0; i < n; i++){
        cin >> height;
        if(i % 2 == 0){
            for(int j = 1; j <= height;j++){
                defense[j - 1]++;
            }
        }
        else{
            for(int j = 0; j < height;j++){
                defense[h - 1 - j] ++;
            }
        }
    }

    for(int i = 0; i < h;i++){
        if(defense[i] < sum){
            cnt = 1;
            sum = defense[i];
        }else if(defense[i] == sum)
            cnt++;
    }

    cout << sum << " "<< cnt;
    
}
*/