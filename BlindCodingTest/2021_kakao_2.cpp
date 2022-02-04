#include <bits/stdc++.h>
using namespace std;



vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int check[26];
    for (int i = 0; i < 26; i++) check[i] = 0;

    for (auto u : orders)
    {
        for (int i = 0; i < u.size(); i++)
        {
            check[u[i] - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        cout << char(i + 'A') << " ";
    }cout << "\n";
    for (int i = 0; i < 26; i++)
    {
        cout << check[i] << " ";
    }
    return answer;
}

int main()
{
    
    vector<string> order = {"ABCFG","AC","CDE","ACDE","BCFG","ACDEH"};
    vector<string> order1 = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
    vector<string> order2 = {"XYZ", "XWY", "WXA"};
    
    vector<int> course = {2,3,4};
    vector<int> course1 = {2,3,5};
    vector<int> course2 = {2,3,4};

    solution(order, course);


	return 0;
}