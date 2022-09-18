#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> &v, int index)
{
}

void redix_sort(vector<int> &v)
{
    int M = *max_element(v.begin(), v.end());

    for (int i = 1; M / i > 0; i *= 10)
    {
    }
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    vector<int> v;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    int ptr1 = v.size() - 1;

    for (int i = 0; i < v.size(); i++)
    {
        if(v[i]<0){
            
        }
    }
}