#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int size){
    for(int i=1;i<size;i++){
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
}

int main()
{
    int arr[] = {2,3,3,5,4,6,3,2};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr,size);
    for (auto i : arr)
        cout << i << " ";
}