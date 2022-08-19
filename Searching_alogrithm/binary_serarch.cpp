#include <bits/stdc++.h>
using namespace std;

int b_search(int arr[], int l, int e, int value)
{
    while (l <= e)
    {
        int m = (l + e) / 2;
        if (arr[m] == value)
        {
            return m;
        }
        else if (value > arr[m])
        {
            l = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return -1;
}

void print(int a){
    cout<<a<<" ";
}

int main()
{
    int arr[] = {7, 3, 9, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + size);
    for_each(arr,arr+size,print);
    cout<<endl;
    cout << b_search(arr, 0, size - 1, 6);
}