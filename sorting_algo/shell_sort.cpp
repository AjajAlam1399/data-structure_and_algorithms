#include <iostream>
using namespace std;

void shell_sort(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int j = gap; j < size; j++)
        {
            int temp = arr[j];
            int i = 0;
            for (i = j; i >= gap && arr[i - gap] > temp; i -= gap)
            {
                arr[i] = arr[i - gap];
            }
            arr[i] = temp;
        }
    }
}
int main()
{
    int arr[] = {170, 75, 802, 90, 66, 2, 24, 45, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    shell_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}