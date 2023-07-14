#include <string>
#include <vector>
using namespace std;
int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
int solution(vector<int> arr)
{
    while (arr.size() > 1)
    {
        int a = arr.back();
        arr.pop_back();
        int b = arr.back();
        arr.pop_back();
        arr.push_back(lcm(a, b));
    }
    return arr[0];
}