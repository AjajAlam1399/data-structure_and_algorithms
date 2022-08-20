#include <bits/stdc++.h>
using namespace std;

void counting_sort(int arr[], int size, int div)
{
    int temp_arr[10];
    int duplicate_arr[size];
    for (int i = 0; i <10; i++)
    {
        temp_arr[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        ++temp_arr[(arr[i]/div)%10];
    }
    for (int i = 1; i <10; i++)
    {
        temp_arr[i] += temp_arr[i - 1];
    }
    for (int i =size-1; i>=0; i--)
    {
        duplicate_arr[--temp_arr[(arr[i]/div)%10]] = arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = duplicate_arr[i];
    }
}

void Redix_sort(int arr[],int size){
    int m=*max_element(arr,arr+size);
    for(int div=1;m/div>0;div*=10){
        counting_sort(arr,size,div);
    }
}

int main()
{
    int arr[] = {6, 3, 9, 1, 7, 8,8,67,90,345,23,987};
    int size = sizeof(arr) / sizeof(arr[0]);

   Redix_sort(arr,size);
    for (auto i : arr)
        cout << i << " ";
}