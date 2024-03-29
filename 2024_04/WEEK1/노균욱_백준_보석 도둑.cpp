/*
보석 도둑

n개를 털려한다.

무게 m.i 가치 v.i를 가지고 있고 각 가방 최대 하중 K.i

가방에는 보석 최대 한개만 넣을 수 있음

훔칠 수 있는 최대 가격  

음.. 그리디로 그냥 무게 중에서 넣을 수 있는 최대가치 놈 슉슉 넣어버리면 끝 아니누?
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct jewel{
    int weight;
    int price;
};


bool cmp(const jewel &a, const jewel & b){
    return a.weight < b.weight;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k, sum = 0;
    int weight, price;

    vector<int> backpack;
    vector<jewel> v;
    cin >> n >> k;

    for(int i = 0 ; i < n; i++){
        cin >> weight >> price;
        v.push_back({weight,price});
    }

    for(int i = 0; i < k; i++){
        cin >> weight;
        backpack.push_back(weight);
    }

    sort(backpack.begin(), backpack.end());
    sort(v.begin(),v.end(), cmp);

    priority_queue<int> pq_price;
    int idx = 0;

    for(int i = 0 ; i < k;i++){
        for(int j = idx; j < n; j++){
            if(v[j].weight <= backpack[i]){
                pq_price.push(v[j].price);
                idx++;
            }else 
                break;
        }

        if(!pq_price.empty()){
            sum += pq_price.top();
            pq_price.pop();
        }
    }

    cout << sum;
}


    // cout<<"\n\n";
    // for(int i = 0 ; i < n; i++){
    //     cout<<v[i].price<<" "<<v[i].weight << "\n";
    // }
    // cout<<"\n\n";
    // for(int i = 0; i < k; i++){
    //     cout<<backpack[i]<<"\n";
    // }
