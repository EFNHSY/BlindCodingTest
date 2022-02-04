#include <bits/stdc++.h>
using namespace std;

vector<int> getFailure(string p)
{
	int m = p.size(), j = 0;
	vector<int> fail(m,0);
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
	vector<int> ans;
	vector<int> fail = getFailure(p);

	for (int i = 0; i < n; i++)
	{
		while (j > 0 && s[i] != p[j])
		{
			if (p[j] == '?') {
				j++; break;
			}
			j = fail[j - 1];
		}
		if (s[i] == p[j]||p[j]=='?')
		{
			if (j == m - 1)
			{
				ans.push_back(j - m + 1);
				j = fail[j];
			}
			else
			{
				j++;
			}
		}
	}
	return ans;
}
vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	string Text;
	for (int i = 0; i < words.size(); i++)
	{
		Text += words[i] + " ";
	}
	vector<int> ans = kmp(Text, "fro??");
	for (auto u : ans)
	{
		cout << u << "\n";
	}
	return answer;
}

int main()
{
	vector<string> text = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };

	solution(text, queries);
	return 0;
}