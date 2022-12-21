#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string topsort(vector<int> adj[], int k)
    {

        string ans;
        vector<int> indegree(k, 0);

        for (int i = 0; i < k; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < k; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int v = q.front();

            ans.push_back('a' + v);
            q.pop();

            for (auto it : adj[v])
            {
                indegree[it]--;

                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return ans;
    }
    string findOrder(string dict[], int n, int k)
    {
        // code here
        vector<int> adj[k];

        for (int i = 0; i < n - 1; i++)
        {
            string str1 = dict[i];
            string str2 = dict[i + 1];
            int len = min(str1.size(), str2.size());
            for (int j = 0; j < len; j++)
            {
                if (str1[j] != str2[j])
                {
                    adj[str1[j] - 'a'].push_back(str2[j] - 'a');
                    break;
                }
            }
        }

        return topsort(adj, k);
    }
};