#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here 
        int count=0;
        
        for(int i=0;i<array.size();i++){
            if(array[i]<a){
                swap(array[count],array[i]);
                count++;
            }
        }
        for(int i=0;i<array.size();i++){
            if(array[i]>=a && array[i]<=b){
                swap(array[count],array[i]);
                count++;
            }
        }
        
    }
};