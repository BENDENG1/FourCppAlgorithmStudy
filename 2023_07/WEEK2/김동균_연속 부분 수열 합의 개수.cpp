#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int solution(vector<int> elements)
{
    int n = elements.size();
    unordered_set<int> sums;

    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = i; j < i + n; ++j)
        {
            sum += elements[j % n];
            sums.insert(sum);
        }
    }

    return sums.size();
}