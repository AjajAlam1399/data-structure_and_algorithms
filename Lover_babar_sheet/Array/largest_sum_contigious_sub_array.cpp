#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[] = {5, 3, -9, 1, 2, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int result, sum;
    result = INT_MIN;
    sum = 0;

    for (int i = 0; i < size1; i++)
    {
        sum += arr1[i];

        if (result < sum)
        {
            result = sum;
        }
        if(sum<0){
            sum=0;
        }
    }

    cout<<result;
}