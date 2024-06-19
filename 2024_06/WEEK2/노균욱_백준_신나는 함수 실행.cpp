/*
신나는 함수 실행 

걍 DP로 갱신해서 0 아니면 return 해주면 될듯 ㅇㅇ 
*/
#include <iostream>

using namespace std;

int arr[21][21][21] = {0,};


int solve(int a, int b, int c){
    if(a <= 0 || b <=0 || c <= 0){
        return 1;
    }
    if(a > 20 || b > 20 || c > 20){
        return solve(20, 20, 20);
    }
    if(arr[a][b][c] != 0){
        return arr[a][b][c];
    }
    if(a < b && b < c){
        arr[a][b][c] = solve(a, b, c - 1) + solve(a, b -1 , c - 1) - solve(a, b - 1, c);
        return arr[a][b][c];
    }
    arr[a][b][c] =  solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1);
    return arr[a][b][c];
}

void printABC(int a, int b, int c){
    cout<<"w(" << a << ", " << b << ", " << c << ") = "<<solve(a, b, c)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    while(1){
        int a, b, c;
        cin >> a >> b >> c;

        if(a == -1 && b == -1 && c == -1){
            break;
        }
        printABC(a,b,c);
    }
}