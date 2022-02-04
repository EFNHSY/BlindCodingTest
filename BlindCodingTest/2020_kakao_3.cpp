#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> up(vector<vector<int>> key)
{
    vector<vector<int>> temp;


    return temp;
}
vector<vector<int>> down(vector<vector<int>> key)
{
    vector<vector<int>> temp;


    return temp;
}
vector<vector<int>> right(vector<vector<int>> key)
{
    vector<vector<int>> temp;


    return temp;
}
vector<vector<int>> left(vector<vector<int>> key)
{
    vector<vector<int>> temp;


    return temp;
}
vector<vector<int>> rotateR(vector<vector<int>> key)
{
    vector<vector<int>> temp;


    return temp;
}
vector<vector<int>> rotateL(vector<vector<int>> key)
{
    vector<vector<int>> temp;


    return temp;
}



bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    bool answer = true;
    int cnt1 = 0, cnt2 = 0;
    int n = key.size(), m = lock.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (key[i][j]) cnt1++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; m; j++)
        {
            if (lock[i][j]) cnt2++;
        }
    }
    if (cnt2 > cnt1) return false;

    bool ok = true;

    for (int i = 0; i < m - n+1; i++)
    {
        for (int j = 0; j < m - n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    if(lock[i+k][j+l]==1&&key[k][l]==1) {}
                }
            }
        }
    }


    return answer;
}

int main()
{


	return 0;
}