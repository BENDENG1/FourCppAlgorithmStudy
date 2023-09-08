#include <string>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

long long binary(string str){
    long long n=0;
    for(int i=0; i< str.size(); i++){
        if(str[i] == '1')
            n += pow(2,str.size()-(i+1));
    }
    return n;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    string str="";
    for(int i=0; i<numbers.size(); i++){
        bitset<64>a(numbers[i]);
        str = a.to_string();
        if(numbers[i]%2 !=0){
            for(int j=str.size()-1; j>=0; j--){
                if(str[j] == '1'){ 
                    if(str[j-1] == '0'){
                        str[j] -= 1;
                        str[j-1] += 1;
                        break;
                    }
                }
                if(j == 0){ // 전부 1일 경우 
                    str[j] = '0';
                    str = '1' + str;
                }
            }
            answer.push_back(binary(str));
        }
        else
            answer.push_back(numbers[i]+1);
    }
    return answer;
}
