#include <bits/stdc++.h>
using namespace std;

string solution(string p) {
    string answer = "";
    stack<char> s;
    string u = "", v = "";
    bool flag = false;
    int k=0, cnt1 = 0, cnt2 = 0;

    // 올바른 괄호문자열 확인 코드 
    for (int i = 0; i < p.size(); i++)
    {

        if (p[i] == '(') s.push('(');
        else
        {
            if (!s.empty()) s.pop();
        }
    }
    if (s.empty()) flag = true;
    
    if (flag) return p;
    while (!s.empty()) s.pop();

    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(') cnt1++;
        else cnt2++;

        if (cnt2 == cnt1)
        {
            k = i+1;
            break;
        }
    }

    u = p.substr(0, k);
    v = p.substr(k, p.size());
    
    // u가 올바른 문자열인지 확인 
    flag = false;
    for (int i = 0; i < u.size(); i++)
    {

        if (u[i] == '(') s.push('(');
        else
        {
            if (!s.empty()) s.pop();
        }
    }
    if (s.empty()) flag = true;
    
    v = solution(v);
    
    if (flag) return u + v;

    answer = "(" + v + ")"; 
    for (int i = 1; i < u.size() - 1; i++)
    {
        if(u[i]==')') answer.push_back('(');
        else answer.push_back(')');
        
    }

    return answer;
}

int main()
{
    stack<char> s;
    string p = "";
    cin >> p;
    cout << solution(p);
	return 0;
}