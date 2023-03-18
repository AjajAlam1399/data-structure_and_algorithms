#include<bits/stdc++.h>
using namespace std;

class Solution
{
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    public:
    //Function to insert heap.
    void insertHeap(int &num)
    {
         if(maxheap.empty() && minheap.empty()){
            maxheap.push(num);
        }
        else{
            if(maxheap.top()<num){
                minheap.push(num);
            }
            else{
                maxheap.push(num);
            }
        }
        
        balanceHeaps();
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int mxh=maxheap.size();
        int mnh=minheap.size();

        if(mxh-mnh==2 || mxh-mnh==-2){
            if(mxh>mnh){
                int element=maxheap.top();
                maxheap.pop();
                minheap.push(element);
            }
            else{
                int element=minheap.top();
                minheap.pop();
                maxheap.push(element);
            }
        }
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        int mxh=maxheap.size();
        int mnh=minheap.size();

        if((mxh+mnh)%2==0){
            return ((maxheap.top()+minheap.top())*1.0)/2.0;
        }
        else{
            if(mxh>mnh){
                return maxheap.top();
            }
            else{
                return minheap.top();
            }
        }
        
    }
};