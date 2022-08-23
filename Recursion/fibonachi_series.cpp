#include <iostream>
using namespace std;

int fibonochi_series(int n, int arr[])
{
    if (n <= 1)
    {
        arr[n] = n;
        return n;
    }

    else
    {
        if (arr[n - 2] == -1)
        {
            arr[n - 2] = fibonochi_series(n - 2, arr);
        }
        if (arr[n - 1] == -1)
        {
            arr[n - 1] == fibonochi_series(n - 1, arr);
        }
        return fibonochi_series(n - 2, arr) + fibonochi_series(n - 1, arr);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)arr[i]=-1;
    cout<<fibonochi_series(n,arr);
}