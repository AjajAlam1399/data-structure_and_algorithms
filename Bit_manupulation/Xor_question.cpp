 
 // construct a array of xor which contain xor or every element execpt the element that is present at the current index

 #include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 1, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int temp=0;
    for(int i=0;i<size;i++){
        temp^=arr[i];
    }

    for(int i=0;i<size;i++){
        arr[i]=arr[i]^temp;
    }

    for(auto i:arr)cout<<i<<" ";
}