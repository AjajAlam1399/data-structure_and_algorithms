#include <bits/stdc++.h>
using namespace std;

void Tower_of_Honi(int n, int A, int B, int C)
{

    if (n > 0)
    {
        Tower_of_Honi(n - 1, A, C, B);
        cout << "moving from tower " << A << " to tower " << C << endl;
        Tower_of_Honi(n - 1, B, A, C);
    }
}

int main()
{
    Tower_of_Honi(3,1,2,3);
}