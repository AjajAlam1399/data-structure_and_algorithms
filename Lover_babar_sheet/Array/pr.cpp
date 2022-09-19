#include <bits/stdc++.h>
using namespace std;

int medium_of_two_sorted_array(int arr1[],int arr2[],int n,int m){
    multiset<int>s(arr1,arr1+n);
    s.insert(arr2,arr2+m);

    vector<int>v(s.begin(),s.end());

    int size=v.size();

    int index;

    if(size%2!=0){
        index=(size+1)/2;

        return v[index-1];
    }
    else{
        index=size/2;

        return floor((v[index]+v[index-1])/2);
    }
}
int main(){
    int arr1[]={1,2};
    int size1=sizeof(arr1)/sizeof(arr1[0]);

    int arr2[]={3,4};
    int size2=sizeof(arr2)/sizeof(arr2[0]);

    multiset<int>s(arr1,arr1+size1);
    s.insert(arr2,arr2+size2);

    vector<int>v(s.begin(),s.end());
    for(auto i : v) cout<<i<<" ";

    cout<<endl;
    int index=v.size()/2;

    cout<<index<<" "<<v[index-1]<<" "<<v[index];

    cout<<endl;
    // cout<<(2+3)/2;

    float sum = (v[index-1]+v[index]);
    float ans=sum/2;
    cout<<ans;
}