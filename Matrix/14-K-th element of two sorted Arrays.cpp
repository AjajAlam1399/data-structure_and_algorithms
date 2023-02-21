#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int s=min(arr1[0],arr2[0]);
        int e=max(arr1[n-1],arr2[m-1]);
        
        while(s<e){
            int mid=(s+e)/2;
            int cnt=0;
            cnt+=count(arr1,n,mid);
            cnt+=count(arr2,m,mid);
            if(cnt<k)s=mid+1;
            else e=mid;
        }
        return s;
    }
    int count(int arr[],int n,int k){
        auto it=upper_bound(arr,arr+n,k);
        
        return it-arr;
    }
};