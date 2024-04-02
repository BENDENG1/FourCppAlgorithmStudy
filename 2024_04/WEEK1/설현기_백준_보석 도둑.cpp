#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct Jewerly{
	int weight;
	int value;
};

struct valuecmp{
	bool operator()(const Jewerly& a, const Jewerly& b){
		return a.value < b.value;
	}
};

bool weightcmp(const Jewerly& a, const Jewerly&b){
	return a.weight < b.weight;
}

int main(){
    int n, k, idx = 0;
    long long result = 0;
    vector<Jewerly> jew;
    vector<int> bag;
    
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        int m, v;
        cin >> m >> v;
        jew.push_back({m, v});
    }
    
    for(int j = 0; j < k; j++){
        int c;
        cin >> c;
        bag.push_back(c);
    }
    
    sort(jew.begin(), jew.end(), weightcmp);
    sort(bag.begin(), bag.end());
    
    priority_queue<Jewerly, vector<Jewerly>, valuecmp> pq;
    
    for(int i = 0; i < k; i++){
        while(idx < n & jew[idx].weight <= bag[i]){
            pq.push(jew[idx]);
            idx++;
        }
        if(!pq.empty()){
			result += pq.top().value;
			pq.pop();
		}
    }
    
    cout << result << "\n";
    
    return 0;
}