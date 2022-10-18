#include <bits/stdc++.h>
using namespace std;

void print_subseq(int s, int n, int arr[], vector<int> &ans, int k)
{
    if (s == n)
    {
        if (accumulate(ans.begin(), ans.end(),0)==k)
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    ans.push_back(arr[s]);
    print_subseq(s + 1, n, arr, ans,k);
    ans.pop_back();
    print_subseq(s + 1, n, arr, ans,k);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans;
    print_subseq(0, n, arr, ans,4);
}