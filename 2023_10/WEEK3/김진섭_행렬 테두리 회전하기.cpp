//문제풀이: https://githubseob.tistory.com/186

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer(queries.size(), 0);
    vector<vector<int>>board(rows, vector<int>(columns, 0));
    int num(1);
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < columns; ++x) {
            board[y][x] = num++;
        }
    }

    for (int i = 0; i < queries.size(); ++i) {
        int start_y(queries[i][0] - 1);
        int start_x(queries[i][1] - 1);
        int end_y(queries[i][2] - 1);
        int end_x(queries[i][3] - 1);

        int y(0), x(0);
        vector<int>nums;
        y = start_y;
        for (x = start_x; x < end_x; ++x) nums.push_back(board[y][x]);

        x = end_x;
        for (y = start_y; y < end_y; ++y) nums.push_back(board[y][x]);

        y = end_y;
        for (x = end_x; x > start_x; --x) nums.push_back(board[y][x]);

        x = start_x;
        for (y = end_y; y > start_y; --y) nums.push_back(board[y][x]);

        int idx(0);
        y = start_y;
        for (x = start_x + 1; x <= end_x; ++x) board[y][x] = nums[idx++];

        x = end_x;
        for (y = start_y + 1; y <= end_y; ++y) board[y][x] = nums[idx++];

        y = end_y;
        for (x = end_x - 1; x >= start_x; --x) board[y][x] = nums[idx++];

        x = start_x;
        for (y = end_y - 1; y >= start_y; --y) board[y][x] = nums[idx++];

        answer[i] = *min_element(nums.begin(), nums.end());
    }

    return answer;
}