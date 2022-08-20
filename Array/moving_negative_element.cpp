#include <bits/stdc++.h>
using namespace std;

void moving_negative_element(int arr[], int size)
{
    int watch = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[i], arr[watch]);
            watch++;
        }
    }
}

void print(int a)
{
    cout << a << " ";
}

int main()
{
    int arr[] = {7, -2, 6, 1, -3, -8, 8, 1, 0, -2};
    int size = sizeof(arr) / sizeof(arr[0]);

    for_each(arr, arr + size, print);
    cout << endl;
    moving_negative_element(arr, size);
    for_each(arr, arr + size, print);
}