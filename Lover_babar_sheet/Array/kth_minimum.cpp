#include <bits/stdc++.h>
using namespace std;

int kth_min(int arr[], int size, int kth)
{
    sort(arr, arr + size);

    return arr[kth - 1];
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout<<kth_min(arr,size,2);
}