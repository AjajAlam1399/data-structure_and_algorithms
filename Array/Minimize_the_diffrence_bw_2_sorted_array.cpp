#include <bits/stdc++.h>
using namespace std;

int mindiff(vector<int> arr1, vector<int> arr2, vector<int> arr3)
{

    vector<int> v;
    v.push_back(arr1.back());
    v.push_back(arr2.back());
    v.push_back(arr3.back());

    int n = *min_element(v.begin(), v.end());

    auto it1 = upper_bound(arr1.begin(), arr1.end(), n);
    int a = *(it1-1);
    auto it2 = upper_bound(arr2.begin(), arr2.end(), n);
    int b = *(it2-1);
    auto it3 = upper_bound(arr3.begin(), arr3.end(), n);
    int c = *(it3-1);

    cout << n << " " << a << " " << b << " " << c << " "<< endl;
    vector<int> result;

    result.push_back(a);
    result.push_back(b);
    result.push_back(c);

    return *max_element(result.begin(), result.end()) - *min_element(result.begin(), result.end());
}

int main()
{
    vector<int> arr1 = {5, 8, 10, 15};
    vector<int> arr2 = {6, 9,9,9,9, 15, 78, 89};
    vector<int> arr3 = {2, 3, 6, 6, 8, 8, 10};

    cout << mindiff(arr1, arr2, arr3);
}