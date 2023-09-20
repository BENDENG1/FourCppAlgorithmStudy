#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    if (num % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    vector<int> numList;

    do {
        for (int len = 1; len <= numbers.length(); ++len) {
            for (int start = 0; start <= numbers.length() - len; ++start) {
                string subStr = numbers.substr(start, len);
                int num = stoi(subStr);
                if (subStr[0] != '0' && isPrime(num)) {
                    numList.push_back(num);
                }
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    sort(numList.begin(), numList.end());
    numList.erase(unique(numList.begin(), numList.end()), numList.end());
    answer = numList.size();

    return answer;
}