#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3};
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {

        for (int j = i; j < 3; j++)
        {
            int curr = 0;
            for (int k = i; k <= j; k++)
            {
                curr += arr[k];
            }
            sum+=curr;
        }
    }

    cout << sum << endl;
}