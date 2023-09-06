#include <string>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    int x = 0;
    int y = 0;
    int dx, dy;
    set<pair<int, pair<pair<int, int>, pair<int, int>>>> mySet;

    for (char d : dirs) {
        dx = x;
        dy = y;
        if (d == 'U') {
            dy++;
        } else if (d == 'D') {
            dy--;
        } else if (d == 'R') {
            dx++;
        } else if (d == 'L') {
            dx--;
        }
        if (dy < -5 || 5 < dy || dx < -5 || 5 < dx) {
            continue;
        }

        if (d == 'U') {
            mySet.insert(make_pair(0, make_pair(make_pair(x, y), make_pair(dx, dy))));
        } else if (d == 'D') {
            mySet.insert(make_pair(1, make_pair(make_pair(x, y), make_pair(dx, dy))));
        } else if (d == 'R') {
            mySet.insert(make_pair(2, make_pair(make_pair(x, y), make_pair(dx, dy))));
        } else if (d == 'L') {
            mySet.insert(make_pair(3, make_pair(make_pair(x, y), make_pair(dx, dy))));
        }

        if (d == 'U') {
            mySet.insert(make_pair(1, make_pair(make_pair(dx, dy), make_pair(x, y))));
        } else if (d == 'D') {
            mySet.insert(make_pair(0, make_pair(make_pair(dx, dy), make_pair(x, y))));
        } else if (d == 'R') {
            mySet.insert(make_pair(3, make_pair(make_pair(dx, dy), make_pair(x, y))));
        } else if (d == 'L') {
            mySet.insert(make_pair(2, make_pair(make_pair(dx, dy), make_pair(x, y))));
        }

        x = dx;
        y = dy;
    }
    answer = mySet.size() / 2;
    return answer;
}