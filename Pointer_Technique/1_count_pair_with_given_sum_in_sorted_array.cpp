#include <bits/stdc++.h>
using namespace std;

int count(int arr[], int size, int k)
{
    int s, e;
    s = 0;
    e = size - 1;
    int count;
    int result = 0;
    int m;

    while (s != e)
    {
        if (arr[s] + arr[e] == k)
        {
            count = 1;
            m = s + 1;
            while (arr[s] == arr[m])
            {
                count++;
                m++;
            }

            result += count;
            if (m == e)
            {
                break;
            }
            e--;
        }
        else if (arr[s] + arr[e] > k)
        {
            e--;
        }
        else if (arr[s] + arr[e] < k)
        {
            s++;
        }
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    vector<int> result;
    while (t--)
    {
        int size;
        cin >> size;
        int k;
        cin >> k;
        int arr[size];
        int num;

        for (int i = 0; i < size; i++)
        {
            cin >> num;
            arr[i] = num;
        }
        result.push_back(count(arr, size, k));
    }
    for (auto it : result)
        cout << it << endl;
}