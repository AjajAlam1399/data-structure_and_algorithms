#include <bits/stdc++.h>
using namespace std;

class Decreasing
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main()
{
    int arr[] = {3, 6, 1, 8, 9, 5, 3, 6, 9, 2, 4, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + size, Decreasing()); // predector as class treat as method

    for (auto i : arr)
        cout << i << " ";
}