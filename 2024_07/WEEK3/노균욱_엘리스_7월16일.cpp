/*
계기판 조작하기 

n -> n보다 크면서 가장 작은수 
k개의 숫자를 하면 되는거임


*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

void updateMap(map<int, int> &m, int digit, int num){
    m[digit] += num;
    if (m[digit] == 0)
        m.erase(digit);
}


int main() {
    ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);

    int n, k;
    map<int, int> m; //숫자, 카운트

    cin >> n >> k;

    int tmp = n;
    while(tmp != 0){
        m[tmp % 10] += 1;
        tmp /= 10;
    }

    while(1){
        int carry = 1;
        tmp = n;

        while(carry > 0 && tmp > 0){
            int digit = tmp % 10;

            updateMap(m,digit,-1);
            digit = (digit + carry) % 10;
            if(digit ==0)
                carry = 1;
            else
                carry = 0;
            updateMap(m,digit,1);
            tmp /= 10;
        }

        if(carry > 0){
            updateMap(m,1,1);
        }
        n++;
        if(m.size() == k){
            cout << n;
            break;
        }
    }
}
