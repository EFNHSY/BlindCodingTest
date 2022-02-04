#include <bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    string answer = "";
    int s_size = new_id.size();
    
    // step 1 
    for (int i = 0; i < s_size; i++)
    {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
        {
            new_id[i] = new_id[i] + 32;
        }
    }
    
    // step 2
    for (int i = 0; i < s_size; i++)
    {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' ||  new_id[i] == '_'|| new_id[i]=='.') answer.push_back(new_id[i]);
        
    }
    
    //step3
    string temp = answer;
    answer = "";
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == '.')
        {
            answer.push_back(temp[i]);
            while (i < temp.size() && temp[i] == '.') i++;
            i--;
        }
        else
        {
            answer.push_back(temp[i]);
        }
    }
    
    //step[4]
    if (answer.size()>0&&answer[0] == '.') answer = answer.substr(1, answer.size());
    
    if (answer.size()>0&&answer[answer.size() - 1] == '.') answer = answer.substr(0, answer.size() - 1);


    /**/
    if (answer.size() == 0) answer += "a";

    if (answer.size() > 15)
    {
        answer = answer.substr(0, 15);
    }
    if (answer.back() == '.') answer.pop_back();

    char temp2 = answer[answer.size() - 1];
    if (answer.size() <= 2)
    {
        while (answer.size() < 3) answer += temp2;
    }

    
    return answer;
}

int main()
{
    int q; cin >> q;
    while (q--)
    {
        string x; cin >> x;
        cout << solution(x) << "\n";
    }
    return  0;

}