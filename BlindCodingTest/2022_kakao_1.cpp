#include <bits/stdc++.h>
using namespace std;

map<string, int> report_cnt;
map<string, vector<string>> report_list;
map<pair<string, string>, bool> isUnique;
set<string> byebyeID;

vector<int> solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k)
{
    vector<int> answer(id_list_len,0);
    for (int i = 0; i < id_list_len;i++)
    {
        string s = id_list[i];
        //report_list[s].push_back("");
        report_cnt[s] = 0;
    }
    
    for (int i = 0; i < report_len; i++)
    {
        string s = report[i];
        int j = s.find(' ');
        string reporter = s.substr(0, j);
        string reported = s.substr(j + 1, s.size());

        if (isUnique.find({ reporter,reported }) != isUnique.end())
        {
            // 이미 신고함.
            continue;
        }
        else
        {
            //cout << "yes\n";
            report_list[reporter].push_back(reported);
            isUnique[{reporter, reported}] = true;
            report_cnt[reported] += 1;
            if (report_cnt[reported] >= k) byebyeID.insert(reported);
        }

    }
    
    int l = 0;
    for (int i = 0; i < id_list_len; i++)
    {
        
        string s = id_list[i];
        
        for (auto x : report_list[s])
        {
            if (byebyeID.find(x) != byebyeID.end())
            {
                
                answer[l ]++;
            }
        }
       
        l++;
    }
    
    for (auto u : answer)
    {
        cout << u << " ";
    }
    return answer;
}
int main()
{
    //const char* id_list[] = { "muzi", "frodo", "apeach", "neo" };
    //const char* report[] = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
    const char* id_list[] = { "con", "ryan" };
    const char* report[] = { "ryan con", "ryan con", "ryan con", "ryan con" };
    vector<int> answer = solution(id_list, 4, report, 5, 2);
	return 0;
}