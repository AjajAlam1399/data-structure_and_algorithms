#include <bits/stdc++.h>
using namespace std;

void moving_negtive_elemnent(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[count], arr[i]);
            count++;
        }
    }
}
int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }
    moving_negtive_elemnent(arr, size);

    for (auto i : arr)
        cout << i << " ";
}