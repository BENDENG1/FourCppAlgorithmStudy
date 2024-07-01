#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
using namespace std;

#define MAX 200000

int T, F;
int parent[MAX + 1];
int friend_num[MAX + 1];
string s1, s2;

int find(int u)
{
	if (u == parent[u]) return u;
	else return find(parent[u]);
}

void union_friend(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u != v)
	{
		parent[u] = v;
		friend_num[v] += friend_num[u];
		friend_num[u] = 1;
	}

	cout << friend_num[v] << '\n';
}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> F;
		int id = 1;
		map<string, int> m;
        
		for (int i = 1; i <= MAX; i++)
		{
			parent[i] = i;
			friend_num[i] = 1;
		}

		for (int i = 1; i <= F; i++)
		{
			cin >> s1 >> s2;

			if (m[s1] == 0)
			{
				m[s1] = id++;
			}

			if (m[s2] == 0)
			{
				m[s2] = id++;
			}

			union_friend(m[s1], m[s2]);
		}
	}


}