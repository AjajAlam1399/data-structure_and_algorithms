#include <bits/stdc++.h>
using namespace std;

void swap_no(int num1, int num2)
{
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
    cout << "no after swap : " << num1 << " " << num2 << endl;
}

int main()
{
    int a = 7, b = 10;

    cout << "no before swap : " << a << " " << b << endl;

    swap_no(a, b);
}