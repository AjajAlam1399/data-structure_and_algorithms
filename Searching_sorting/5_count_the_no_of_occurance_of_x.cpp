#include<bits/stdc++.h>
using namespace std;

int find(int arr[], int n , int x )
{
    // code here
    int first,last;
    first=last=-1;
    
    int s=0,e=n-1;
    
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==x){
            first=mid;
            e=mid-1;
        }
        else if(arr[mid]>x){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    s=0;
    e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==x){
            last=mid;
            s=mid+1;
            
        }
        else if(arr[mid]>x){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return last-first+1;
}

//{ Driver Code Starts.

