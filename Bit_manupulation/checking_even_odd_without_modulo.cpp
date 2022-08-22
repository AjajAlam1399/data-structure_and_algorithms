#include <iostream>

using namespace std;

bool getbit(int n)
{
    return (n & (1 << 0)) != 0;
}

int main()
{
    int num;
    cin >> num;

    if (getbit(num))
    {
        cout << num << " is odd ";
    }
    else
    {
        cout << num << " is even";
    }
}