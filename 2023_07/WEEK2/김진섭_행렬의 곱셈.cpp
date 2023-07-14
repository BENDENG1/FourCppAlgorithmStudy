//문제풀이: https://githubseob.tistory.com/298

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int y(0), x(0), idx(0), idx2(0);
    vector<vector<int>>arr3(arr1.size(), vector<int>(arr2[0].size(), 0));

    for (y = 0; y < arr3.size(); ++y) {
        for (x = 0; x < arr3[0].size(); ++x) {
            for (idx = 0; idx < arr2.size(); ++idx) {
                arr3[y][x] += (arr1[y][idx] * arr2[idx][x]);
            }
        }
    }

    return arr3;
}