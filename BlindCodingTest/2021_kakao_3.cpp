#include <bits/stdc++.h>
using namespace std;


vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	
	vector<int> v[3][2][2][2];
	int a, b, c, d;

	for (int i = 0; i < info.size(); i++)
	{
		int cur = 0, prev = 0;
		string substring;

		cur = info[i].find(' ');
		substring = info[i].substr(prev, cur);
		info[i] = info[i].substr(cur + 1, info[i].size());
		if (substring == "cpp") a = 0;
		else if (substring == "java") a = 1;
		else a = 2;
		prev = 0;

		cur = info[i].find(' ');
		substring = info[i].substr(prev, cur);
		info[i] = info[i].substr(cur + 1, info[i].size());
		if (substring == "backend") b = 0;
		else b = 1;
		prev = 0;

		cur = info[i].find(' ');
		substring = info[i].substr(prev, cur);
		info[i] = info[i].substr(cur + 1, info[i].size());
		if (substring == "junior") c = 0;
		else c = 1;
		prev = 0;

		cur = info[i].find(' ');
		substring = info[i].substr(prev, cur);
		info[i] = info[i].substr(cur + 1, info[i].size());
		if (substring == "chicken") d = 0;
		else d = 1;
		prev = 0;

		int score = stoi(info[i]);

		v[a][b][c][d].push_back(score);
		
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				for (int l = 0; l < 2; l++)
				{
					for (auto u : v[i][j][k][l])
					{
						cout << i << " " << j << " " << k << " " << l << " " << u << "\n";
					}
				}
			}
		}
	}

	return answer;
}

int main()
{
	vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
	vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
	vector<string> x;

	vector<int> ans = solution(info, query);
	
	for (auto u : ans)
	{
		cout << u << "\n";
	}
	return 0;
}