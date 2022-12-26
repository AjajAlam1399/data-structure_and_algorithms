#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        // code here

        int row = grid.size();
        int col = grid[0].size();

        int sri = source.first;
        int srj = source.second;

        int desti = destination.first;
        int destj = destination.second;

        vector<vector<int>> dist(row, vector<int>(col, 1e7));

        dist[sri][srj] = 0;

        queue<pair<int, pair<int, int>>> pq;

        pq.push({0, {sri, srj}});

        while (!pq.empty())
        {
            int rowi = pq.front().second.first;
            int coli = pq.front().second.second;
            int srdist = pq.front().first;

            pq.pop();

            int arr1[] = {1, 0, 0, -1};
            int arr2[] = {0, -1, 1, 0};

            for (int i = 0; i <= 3; i++)
            {
                int nrow = rowi + arr1[i];
                int ncol = coli + arr2[i];

                if (nrow >= 0 && ncol >= 0 && nrow < row && ncol < col && grid[nrow][ncol] == 1 && dist[nrow][ncol] > srdist + 1)
                {
                    dist[nrow][ncol] = srdist + 1;
                    if (nrow == desti && ncol == destj)
                    {
                        break;
                    }
                    pq.push({srdist + 1, {nrow, ncol}});
                }
            }
        }
        if (dist[desti][destj] == 1e7)
        {
            return -1;
        }
        return dist[desti][destj];
    }
};
