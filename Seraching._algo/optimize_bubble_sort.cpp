#include <bits/stdc++.h>
using namespace std;

void optimize_bubble_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        bool flage = false;
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flage = true;
            }
        }
        if (flage == false)
        {
            break;
        }
    }
}
int main()
{
    int arr[] = {1, 2, 4, 6,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    optimize_bubble_sort(arr, size);
    for (auto i : arr)
        cout << i << " ";
}