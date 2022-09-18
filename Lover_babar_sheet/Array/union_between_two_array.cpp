#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[] = {5, 3, 9, 1, 2, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {7, 4, 1, 9, 0, 4, 3, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    vector<int> v;

    copy(arr1, arr1 + size1, back_inserter(v));
    copy(arr2, arr2 + size2, back_inserter(v));

    sort(v.begin(), v.end());

    for (auto it : v)
        cout << it << " ";
    cout << endl;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]!=v[i+1])
        {
            cout << v[i] << " ";
        }
    }

}
int main(){
    
}