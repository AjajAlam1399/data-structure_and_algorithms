#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{

    vector<pair<int, int>> box;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                box.push_back(make_pair(i, j));
            }
        }
    }
    int first;
    int second;

    for (auto it = box.begin(); it != box.end(); it++)
    {
        first = it->first;
        second = it->second;

        for(int i=0;i<matrix[first].size();i++){
            matrix[first][i]=0;
        }

        for(int i=0;i<matrix.size();i++){
            matrix[i][second]=0;
        }
    }
}
int main(){
    cout<<"hello";
}