// write a programm to find unique no where all the on except 2 no  is present twice

#include <bits/stdc++.h>
using namespace std;

bool getbit(int a, int pos)
{
    return (a & (1 << pos)) != 0;
}

int main()
{
    int arr[] = {2, 4, 6, 7, 4, 5, 6, 2};
    int temp = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        temp ^= arr[i];
    }
    int pos = 0;
    while (getbit(temp, pos) == 0)
    {
        pos++;
    }
    int temp2=temp;

    for(int i=0;i<size;i++){
        if(getbit(arr[i],pos)){
            temp2^=arr[i];
        }
    }

    int num1=temp2;
    int num2=temp^temp2;

    cout<<num1<<" "<<num2;

}