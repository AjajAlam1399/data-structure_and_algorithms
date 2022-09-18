#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
{
    // Your code here

    set<int> s(arr, arr + N);

    vector<int> v(s.begin(), s.end());

    int longest =1;
    int count = 1;


    for(int i=1;i<v.size();i++){
        if(v[i]==v[i-1]+1){
            count++;
        }
        else{
            count=1;
        }
        longest=max(longest,count);
    }

    return longest;
}


int main()
{
    int arr[]={1,9,3,10,4,20,2};
    int size=sizeof(arr)/sizeof(arr[0]);

    cout<<findLongestConseqSubseq(arr,size);
}