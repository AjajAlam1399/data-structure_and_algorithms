#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3};
    int sum = 0;
    for(int i=0;i<3;i++){
        sum+=arr[i]*(i+1)*(3-i);
    }

    cout << sum << endl;
}