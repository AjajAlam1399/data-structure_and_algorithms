#include<bits/stdc++.h>
using namespace std;
class Solution
{
    vector<pair<int, int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
    pair<int, int> endPoints(vector<vector<int>> matrix, int R, int C)
    {
        // code here

        queue<pair<int, pair<int, int>>> q;

        q.push({1, {0, 0}});

        while (!q.empty())
        {
            auto v = q.front();
            q.pop();
            int i = v.second.first;
            int j = v.second.second;
            int dir = v.first;

            if (matrix[i][j] == 0)
            {
                while (matrix[i][j] == 0)
                {
                    int newi = i + direction[dir % 4].first;
                    int newj = j + direction[dir % 4].second;
                    if (newi < 0 || newj < 0 || newi >= R || newj >= C)
                    {
                        return {i, j};
                    }
                    else
                    {
                        i = newi;
                        j = newj;
                    }
                }
                if (matrix[i][j] == 1)
                {
                    int newdir = (dir + 1) % 4;
                    int newi = i + direction[newdir].first;
                    int newj = j + direction[newdir].second;
                    if (newi < 0 || newj < 0 || newi >= R || newj >= C)
                    {
                        return {i, j};
                    }
                    else
                    {
                        matrix[i][j] = 0;
                        q.push({dir + 1, {newi, newj}});
                    }
                }
            }
            else
            {
                int newdir = (dir + 1) % 4;
                int newi = i + direction[newdir].first;
                int newj = j + direction[newdir].second;
                if (newi < 0 || newj < 0 || newi >= R || newj >= C)
                {
                    return {i, j};
                }
                else
                {
                    matrix[i][j] = 0;
                    q.push({dir + 1, {newi, newj}});
                }
            }
        }
    }
};