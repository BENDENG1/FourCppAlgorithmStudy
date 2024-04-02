#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sum_(const vector<int>& v) {
	int result = 0;
    
	if (v.size() % 2 == 0) {
		for (int i = 0; i < v.size(); i += 2) {
			if (v[i] * v[i + 1] > v[i] + v[i + 1]) {
                result += v[i] * v[i + 1];
            }
			else {
                result += v[i] + v[i + 1];
            }
		}
	}
	else {
		for (int i = 0; i < v.size() - 1; i += 2) {
			if (v[i] * v[i + 1] > v[i] + v[i + 1]) {
                result += v[i] * v[i + 1];
            }
			else {
                result += v[i] + v[i + 1];
            }
		}
		if (v[v.size() - 1] > 0) {
            result += v[v.size() - 1];
        }
	}
	return result;
}

int main(){
    int n, num, answer = 0;
    cin >> n;
    
    vector<int> zero, minus, plus;
    
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) {
            zero.push_back(num);
        }
		else if (num > 0) {
            plus.push_back(num);
        }
		else {
            minus.push_back(num);
        }
	}
    
    sort(plus.rbegin(), plus.rend());
	sort(minus.begin(), minus.end());
    
    answer += sum_(plus);
    answer += sum_(minus);
    
    if(minus.size() % 2 == 1){
        if(zero.empty()){
            answer += minus[minus.size() - 1];
        }
    }
    
    cout << answer;
    
    return 0;
}