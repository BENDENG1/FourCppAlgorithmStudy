#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string numbers="0123456789ABCDEF";

string convert_num(int n, int base){
    string r="";

    while(n>0){
        r += numbers[n%base];
        n /= base;
    }
    
    reverse(r.begin(), r.end());
    return r;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string a = "0";
    for (int i = 0; a.size() <= t * m; i++){
        a +=  convert_num(i, n);
    }
    
    for(int i = p - 1; i < t * m; i += m){
        answer += a[i];
    }
    
    return answer;
}