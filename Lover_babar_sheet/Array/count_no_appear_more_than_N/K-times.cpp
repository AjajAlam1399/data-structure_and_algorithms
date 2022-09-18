#include <bits/stdc++.h>
using namespace std;

vector<int> no_appear_N_by_k_times(int arr[], int size,int k)
{

    unordered_map<int, int> m;

    int count=size/k;

    for (int i = 0; i < size; i++)
    {
        m[arr[i]]++;
    }

    vector<int> result;

    for (auto it = m.begin(); it != m.end(); it++)
    {
        if(it->second>count){
            result.push_back(it->first);
        }
    }

    return result;
}

int main()
{
    int arr[] = {3,1,2,2,1,2,3,3};
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> result=no_appear_N_by_k_times(arr,size,4);

    for(auto it : result) cout<<it<<" ";
}