
/*
시소 2,3,4 균형 -> 시소 짝꿍

weights -> 시소 짝꿍 몇 쌍 return

정렬 -> 같으면 +, 크면 break? -> 너무 단순하고 요구하는 사항이 아닌거 같음

통과는 했는데 이게 아닌것은 확실하다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int calculate(int num1, int num2);

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<int> v;
    v = weights;
    sort(v.begin(), v.end());
    
    for(int i  = 0; i < v.size(); i++){
        for(int j  = i + 1; j < v.size();j++){
            if(v[i] == v[j]){
                answer++;
                continue;
            }
            else if(v[i] * 4 < 2 * v[j])
                break;
            answer += calculate(v[i], v[j]);
        }
    }
    return answer;
}

int calculate(int num1, int num2){
    for(int i = 2; i <= 4; i++){
        for(int j = 2; j <= 3;j++){
            if(i != j && num1 * i == num2 * j){
                return 1;
            }
        }
    }
    return 0;
}

// #include <string>
// #include <vector>
// #include <algorithm>
// #include <map>

// using namespace std;

// long long solution(vector<int> weights) {
//     long long answer = 0;
    
//     map<int, long long> m;
    
//     for(int i = 0; i < weights.size(); i++)
//     {
//         m[weights[i]]++;
//     }
    
//     for(auto i : m)
//     {   
//         if(i.second > 1) 
//             answer += i.second * (i.second - 1) / 2;

//         long long expected;

//         if(i.first % 2 == 0)
//         {
//             expected = (i.first / 2) * 3;
//             if(expected <= 1000) answer += i.second * m[expected];
//         }

//         if(i.first % 3 == 0)
//         {
//             expected = (i.first / 3) * 4;
//             if(expected <= 1000) answer += i.second * m[expected];
//         }

//         expected = i.first * 2;
//         if(expected <= 1000) answer += i.second * m[expected];
    
//         m[i.first] = 0;
//     }    
    
//     return answer;
// }