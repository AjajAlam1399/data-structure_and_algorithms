#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int count = 0;
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
            count += mid;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= right)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    return count;
}

int count_inversion(int arr[], int temp[], int left, int right)
{
    static int count = 0;

    if (left < right)
    {
        int mid = (left + right) / 2;
        count_inversion(arr, temp, left, mid);
        count_inversion(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid, right);
    }

    return count;
}
int main()
{
    int arr[] = {5, 3, 2, 4, 1};
    int temp[] = {5, 3, 2, 4, 1};

    cout << count_inversion(arr, temp, 0, 4);
}