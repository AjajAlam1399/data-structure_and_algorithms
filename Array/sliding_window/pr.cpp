#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string str, int k)
{
    // your code here

    int s, e;
    e = 0;
    s = 0;

    int result = -1;

    unordered_map<char, int> m;

    while (e < str.size())
    {
        m[str[e]]++;
        if (m.size() < k)
        {
            e++;
        }
        else if (m.size() == k)
        {
            
            result = max(result, e - s + 1);

            e++;
        }
        else if (m.size() > k)
        {

            while (m.size() > k)
            {
                m[str[s]]--;
                if(m[str[s]]==0){
                    m.erase(str[s]);
                }
                s++;
            }
        }
    }
    return result;
}
int main()
{
    cout << longestKSubstr("hq", 2) << endl;
    
    // unordered_map<char,int>m;
    // m['a']=1;
    // m['a']--;
    // if(m['a']==0){
    //     m.erase('a');
    // }
    // cout<<m.size();
}