#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[] = {5, 3, 9, 1, 2, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    rotate(arr1, arr1 +size1 -1, arr1 + size1);

    for (auto it : arr1)
        cout << it << " ";
}