#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3};
    
    int max_sum=arr[0];

    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=i;j<3;j++){
            sum+=arr[j];
            max_sum=max(max_sum,sum);
        }
    }

    cout<<max_sum;
}