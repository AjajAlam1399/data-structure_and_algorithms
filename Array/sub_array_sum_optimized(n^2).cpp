#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3};
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {   int res=0;
        for(int j=i;j<3;j++){
            res+=arr[j];
            sum+=res;
        }
    }

    cout << sum << endl;
}