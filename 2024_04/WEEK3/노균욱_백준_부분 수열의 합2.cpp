/*
부분 수열의 합 2

원소를 다 더한 값이 S가 되는 경우의 수를 구하는거

모든 경우의 수를 계산하면 2^n이니깐 패스

left,right를 구해서 하면 된다

모든 합을 구하는 것은 idx ++ 를 하면서 합을 넣는것과 안넣는것 두가지로 진행

모든 합을 구하는 케이스인데 모두 안하는 모든것을 안더하는 상황에 대해서 0 추가 해야함

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> leftV, rightV;

void leftCase(int idx,int sum, int size, const vector<int> & v){
    if(idx == size){
        leftV.push_back(sum);
        return;
    }
    leftCase(idx + 1, sum, size, v);
    leftCase(idx + 1, sum + v[idx], size, v);
}

void rightCase(int idx,int sum, int size, const vector<int> & v){
    if(idx == size){
        rightV.push_back(sum);
        return;
    }
    rightCase(idx + 1, sum, size, v);
    rightCase(idx + 1, sum + v[idx], size, v);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, s, tmp; 
    long long answer = 0;
    vector<int> v;
    cin >> n >> s;

    for(int i = 0; i < n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    leftCase(0, 0, n/2, v);
    rightCase(n/2, 0, n, v);

    sort(leftV.begin(),leftV.end());
    sort(rightV.begin(), rightV.end());

    for(int i = 0; i < leftV.size(); i ++){
        answer += upper_bound(rightV.begin(),rightV.end(), s - leftV[i]) - lower_bound(rightV.begin(), rightV.end(), s - leftV[i]);
    }
    if(s == 0)
        answer --;
    cout << answer;
}

    // cout<<"\n\n";
    // for(int i =  0; i < leftV.size(); i ++){
    //     cout<<leftV[i] <<"   ";
    // }
    // cout<<"\n\n";
    // for(int i =  0; i < rightV.size(); i ++){
    //     cout<<rightV[i] <<"   ";
    // }
    // cout<<"\n\n";

/*
vector<int> leftV, rightV;
int answer = 0;

void allCase(const vector<int> &v,int sum,int idx, int size){
    if(idx == size)
        return;
    if(size == v.size()){
        rightV.push_back(sum);
    }else{
        leftV.push_back(sum);
    }
    if(sum == answer)
        answer++;
    allCase(v,sum + leftV[idx], idx + 1, size);
    allCase(v,sum, idx + 1, size);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int N, S, tmp;
    vector<int> v;
    cin >> N >> S;

    for(int i = 0 ; i < N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    allCase(v, v[0], 0, N/2);
    allCase(v, v[N/2], N/2, v.size());

    sort(leftV.begin(), leftV.end());
    sort(rightV.begin(), rightV.end());

    for(int i = 0 ; i < leftV.size(); i++){
        answer += (upper_bound(rightV.begin(), rightV.end(), S - leftV[i]) - lower_bound(rightV.begin(),rightV.end(), S- leftV[i]));
        cout << leftV[i] <<"    "<< answer <<"\n";
    }

    cout <<answer;

}
*/