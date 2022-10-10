//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int binary_search(int arr[],int start,int end ,int x){
        while(start<=end){
            int mid=start + (end-start)/2;
            
            if(arr[mid]==x){
                return mid;
            }
            else if(arr[mid]>x){
                end=mid-1;
            }
            else if(arr[mid]<x){
                start=mid+1;
            }
        }
        return -1;
    }
    
    int search(int arr[], int l, int h, int x){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
         int smallest_element_index;
        
        int s=l;
        int n=h+1;
        
        int e=n-1;
        
        int prev,next;
        
        while(s<=e){
            int mid=s+(e-s)/2;
            prev=(mid-1+n)%n;
            next=(mid+1)%n;
            
            if(arr[s]<=arr[e]){
                smallest_element_index=s;
                break;
            }
            if(arr[mid]<arr[prev] && arr[mid]<arr[next]){
                smallest_element_index=mid;
                break;
            }
            else if(arr[mid]>=arr[s]){
                s=mid+1;
            }
            else if(arr[mid]<=arr[e]){
                e=mid-1;
            }
        }
        
        s=l;
        e=n-1;
        if(arr[smallest_element_index]==x){
            return smallest_element_index;
        }
        else if(smallest_element_index==0){
            return binary_search(arr,0,e,x);
        }
        else if(smallest_element_index==e){
            return binary_search(arr,0,e-1,x);
        }
        else{
            if(x>=arr[s] && x<=arr[smallest_element_index-1]){
                return binary_search(arr,s,smallest_element_index-1,x);
            }
            else if(arr[smallest_element_index+1]<=x && arr[e]>=x){
                return binary_search(arr,smallest_element_index+1,e,x);
            }
        }
        return -1;
        
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends

