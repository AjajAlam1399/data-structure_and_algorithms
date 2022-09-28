#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>matrixNew(matrix.size(),vector<int>(matrix.size()));
        
        vector<int>v;
        int size=matrixNew.size()-1;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                v.push_back(matrix[i][j]);
            }
            
            for(int i=0;i<matrix.size();i++){
                matrixNew[i][size]=v[i];
            }
            size--;
            v.clear();
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                matrix[i][j]=matrixNew[i][j];
            }
        }
    }
};