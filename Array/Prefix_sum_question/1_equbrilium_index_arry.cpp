#include<bits/stdc++.h>
using namespace std;

int findEquilibrium(int A[], int n)
{
  //Your code here
  
  if(n<=2){
      return -1;
  }
  int total_sum=0;
  for(int i=0;i<n;i++){
      total_sum+=A[i];
  }
  int ls=A[0];
  int rs;
  int result=-1;
  
  for(int i=1;i<n-1;i++){
      rs=total_sum-ls-A[i];
      if(ls==rs){
          result=i;
          return result;
      }
      ls+=A[i];
  }
  return result;
  
}