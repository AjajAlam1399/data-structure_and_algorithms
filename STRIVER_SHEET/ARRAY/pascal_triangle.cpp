#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
        vector<int>row;
        if(numRows==0){
            return result;
        }
        row.push_back(1);
            result.push_back(row);
            row.clear();
        if(numRows==1){
            return result;
        }
        row.push_back(1);
        row.push_back(1);
        result.push_back(row);
        row.clear();
        if(numRows==2){
            return result;
        }
        
        for(int i=3;i<=numRows;i++){
            row.push_back(1);
            for(int j=0;j<result[i-2].size()-1;j++){
                
                row.push_back(result[i-2][j]+result[i-2][j+1]);
                
            }
            row.push_back(1);
            result.push_back(row);
            row.clear();
        }
        return result;
    }
        
};