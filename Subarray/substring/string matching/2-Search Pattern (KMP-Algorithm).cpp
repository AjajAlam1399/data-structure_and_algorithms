//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            vector<int>ans;
            auto f1=txt.find(pat);
            if(f1!=string::npos){
                ans.push_back(f1+1);
            }
            else{
                return {};
            }
            while(true){
                auto f2=txt.find(pat,f1+1);
                if(f2!=string::npos){
                    ans.push_back(f2+1);
                    f1=f2;
                }
                else{
                    break;
                }
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends