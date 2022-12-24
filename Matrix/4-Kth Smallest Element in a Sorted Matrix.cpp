#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int rank(vector<vector<int>>& matrix, int k){
        int n=matrix.size();
        int m=matrix[0].size();

        int i=0;
        int j=m-1;
        int count=0;
        while(i<n && j>=0){
            if(matrix[i][j]>k){
                j--;
            }
            else{
                count+=j+1;
                i++;
            }
        }

        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();

        int l=matrix[0][0];
        int r=matrix[n-1][n-1];

        while(l<r){
            int mid=l+(r-l)/2;
            int count=rank(matrix,mid);

            if(count<k) l=mid+1;
            else r=mid;
        }

        return l;
    }
};