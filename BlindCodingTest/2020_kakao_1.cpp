#include <bits/stdc++.h>
using namespace std;

vector<int> failure(string p)
{
	int m = p.size(), j = 0;
	vector<int> fail(m, 0);

	for (int i = 1; i < m; i++)
	{
		while (j > 0 && p[i] != p[j]) j = fail[j - 1];
		if (p[i] == p[j]) fail[i] = ++j;
	}

	return fail;
}
vector<int> kmp(string s, string p)
{
	int n = s.size(), m = p.size(), j = 0;
	vector<int> ans(n, 0);
	vector<int> fail = failure(p);

	for (int i = 0; i < n; i++)
	{
		while (j > 0 && s[i] != p[j]) j = fail[j - 1];
		if (s[i] == p[j])
		{
			if (j == m - 1)
			{
				ans.push_back(j - m + 1);
			}
		}
	}

}

int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		string p;
		cin >> p;
		vector<int> fail = failure(p);
		cout << p.size() << " : ";
		for (auto u : fail)
		{
			cout << u << " ";
		}cout << "\n";
	}
	
	return 0;
}