#include <bits/stdc++.h>
using namespace std;

void counting_sort(int arr[], int size, int range)
{
    int temp_arr[range+1];
    int duplicate_arr[size];
    for (int i = 0; i <= range; i++)
    {
        temp_arr[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        ++temp_arr[arr[i]];
    }
    for (int i = 1; i <=range; i++)
    {
        temp_arr[i] += temp_arr[i - 1];
    }
    for (int i = 0; i < size; i++)
    {
        duplicate_arr[--temp_arr[arr[i]]] = arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = duplicate_arr[i];
    }
}

int main()
{
    int arr[] = {6, 3, 9, 1, 7, 8,8};
    int size = sizeof(arr) / sizeof(arr[0]);

    counting_sort(arr, size, 9);
    for (auto i : arr)
        cout << i << " ";
}