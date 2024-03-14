#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int getGCD(int x, int y){
    int tmp;
    while(y != 0){
        tmp = x;
        x = y;
        y = tmp % x;
    }
    return x;
}

int findNum(vector<int> original,vector<int> compare){
    int gcd = original[0];
    
    for(int i = 1; i < original.size();i++){
        gcd = getGCD(gcd,original[i]);
        if(gcd == 1) 
            return 0;
    }
    
    for(int i = 0; i < compare.size();i++){
        if(compare[i] % gcd == 0)
            return 0;
    }
    return gcd;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    int a = findNum(arrayA,arrayB);
    int b = findNum(arrayB,arrayA);

    return max(a,b);
}