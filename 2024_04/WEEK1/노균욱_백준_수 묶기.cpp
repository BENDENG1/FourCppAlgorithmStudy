/*
수 묶기

음 정렬해서 - -  + + 끼리 묵어서 진행?
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, tmp, sum = 0;
    bool isZero  = false;
    vector<int> plus;
    vector<int> minus;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> tmp;
        if(tmp > 0) 
            plus.push_back(tmp);
        else if (tmp < 0) 
            minus.push_back(tmp);
        else 
            isZero = true;
    }

    sort(plus.begin(),plus.end(),greater<int>());
    sort(minus.begin(), minus.end());
    
    if(plus.size() > 0 && plus.size() % 2 != 0)
        plus.push_back(0);

    if(minus.size() > 0 && minus.size() % 2 == 1){
        if(isZero)
            minus.push_back(0);
        else
            minus.push_back(1);
    }

    for(int i = 0 ; i < plus.size(); i += 2){
        if(plus[i] * plus[i+1] > plus[i] + plus[i + 1])
            sum += plus[i] * plus[i + 1];
        else
            sum += (plus[i] + plus[i + 1]);
    }

    for(int i = 0 ; i < minus.size(); i += 2){
        sum += minus[i] * minus[i + 1];
    }


    cout << sum;

    return 0;
}