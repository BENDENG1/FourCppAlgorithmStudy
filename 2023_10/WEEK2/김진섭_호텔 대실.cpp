//문제풀이: https://githubseob.tistory.com/355

#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> s_book_time) {
    int answer(0), hour(0), min(0);
    vector<vector<int>>book_time(s_book_time.size(), vector<int>(2, 0));

    for (int idx = 0; idx < s_book_time.size(); ++idx) {
        hour = stoi(s_book_time[idx][0].substr(0, 2));
        min = stoi(s_book_time[idx][0].substr(3, 2));
        book_time[idx][0] = hour * 60 + min;

        hour = stoi(s_book_time[idx][1].substr(0, 2));
        min = stoi(s_book_time[idx][1].substr(3, 2));
        book_time[idx][1] = hour * 60 + min + 10;
    }

    sort(book_time.begin(), book_time.end());

    priority_queue<int, vector<int>, greater<int>>room;
    for (int idx = 0; idx < book_time.size(); ++idx) {
        int start = book_time[idx][0];
        int end = book_time[idx][1];
        while (!room.empty() && room.top() <= start) {
            room.pop();
        }
        room.push(end);
        int room_size = room.size();
        answer = max(answer, room_size);
    }

    return answer;
}