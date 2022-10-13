//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int getbit(int n,int pos){
        return ((n)&(1<<pos))!=0;
    }
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xor_no=0;
        
        for(int i=0;i<nums.size();i++){
            xor_no=xor_no^nums[i];
        }
        
        int pos=0;
        
        int dupli_xor=xor_no;
        
        while(dupli_xor){
            if(getbit(dupli_xor,0)){
                break;
            }
            pos++;
            dupli_xor=dupli_xor>>1;
        }
        
        int a=xor_no;
        int b;
        
        for(int i=0;i<nums.size();i++){
            if(getbit(nums[i],pos)){
                a^=nums[i];
            }
        }
        
        b=a^xor_no;
        
        vector<int>resul={a,b};
        sort(resul.begin(),resul.end());
        
        return resul;
        
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends