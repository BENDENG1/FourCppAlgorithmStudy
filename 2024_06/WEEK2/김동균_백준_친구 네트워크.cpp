#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
unordered_map<string, string> um;
unordered_map<string, int> nums;

string find(string a)
{
    if (um[a] == a)
    {
        return a;
    }
    else
    {
        return um[a] = find(um[a]);
    }
}

void SetNode(string a, string b)
{
    string A = find(a);
    string B = find(b);

    if (A == B)
        return;

    um[B] = A;
    nums[A] += nums[B];
}

int main(int argc, char** argv)
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int tn;
    cin >> tn;

    while (tn--)
    {
        int n;
        cin >> n;

        um.clear();
        nums.clear();

        for (int i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;
            if (um.count(a) == 0)
            {
                um.insert(make_pair(a, a));
                nums.insert(make_pair(a, 1));
            }
            if (um.count(b) == 0)
            {
                um.insert(make_pair(b, b));
                nums.insert(make_pair(b, 1));
            }
            SetNode(a, b);
            cout << nums[find(a)] << '\n';
        }
    }
}