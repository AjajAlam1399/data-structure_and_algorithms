#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int size)
{
    for (int j = 1; j < size; j++)
    {
        for (int i = 0; i < size - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}
int main()
{
    int arr[] = {1, 5, 6, 8, 2, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, size);
    for (auto i : arr)
        cout << i << " ";
}