#include <bits/stdc++.h>
using namespace std;

#define ln long long int
long long maxArea(long long A[], int len)
{
    // Your code goes here
    int s = 0;
    int e = len - 1;
    ln area;
    ln maxarea = 0;

    while (s < e)
    {
        area = min(A[s], A[e]) * (e - s);
        if (area > maxarea)
            maxarea = area;
        if (min(A[s], A[e]) == A[s])
        {
            s++;
        }
        else
        {
            e--;
        }
    }
    return maxarea;
}