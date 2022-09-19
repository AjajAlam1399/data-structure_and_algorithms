/*Complete the function below*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int PalinArray(int a[], int n)
{
    // code here

    int rev_no;

    int digit;
    int ten_pow;
    int remainder;

    bool flage=true;

    for (int i = 0; i < n; i++)
    {
        rev_no = 0;
        int k = a[i];
        while (k >= 10)
        {
            digit = log10(k);
            ten_pow = pow(10, digit);
            remainder=k%10;

            rev_no+=ten_pow*remainder;
            k/=10;
        }
        rev_no+=k;

        if(rev_no!=a[i]){
            flage=false;
            break;
        }
    }
    return flage;
}
};