#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long p)
{
    if (p == 1) return false;
    for (long long i = 2; i <= sqrt(p); i++)
    {
        if (p % i == 0) return false;
    }
    return true;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}
long long solution(long long n, long long k) {
    long long answer = 0;
    
    string s;
    long long temp = n;
    while (temp)
    {
        s += temp % k + '0';
        temp /= k;
    }
   
    reverse(s.begin(), s.end());
    cout << s << "\n";
    vector<string> num = split(s, '0');
    
    for (auto u : num)
    {
        
        if (u != "")
        {
            cout << u << "\n";
            if (isPrime(stod(u))) answer++; 
        }
        
    }
   
    return answer;
}
int main()
{
    long long ans = solution(1000000, 2);
    cout << ans << "\n";
	return 0;
}