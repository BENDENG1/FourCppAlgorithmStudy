//문제풀이: https://githubseob.tistory.com/380

#include <string>
#include <vector>
using namespace std;

string type[4] = { "RR", "Rr", "Rr", "rr" };
string answer;

string find_parent(int gen, int idx) {
    if (gen == 1) {
        return "Rr";
    }
    else if (gen == 2) {
        return type[idx];
    }
    else {
        string parent = find_parent(gen - 1, idx / 4);
        if (parent == "RR") {
            return "RR";
        }
        else if (parent == "Rr") {
            return type[idx % 4];
        }
        else if (parent == "rr") {
            return "rr";
        }
    }
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string>ret;
    for (int idx = 0; idx < queries.size(); ++idx) {
        ret.push_back(find_parent(queries[idx][0], queries[idx][1] - 1));
    }
    return ret;
}
출처: https://githubseob.tistory.com/380 [GitHubSeob:티스토리]