//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class cmp{
    public:
    bool operator()(tuple<int,int,int>t1,tuple<int,int,int>t2){
        if(get<2>(t1)==get<2>(t2)){
            return get<0>(t1)<get<0>(t2);
        }
        return get<2>(t1)<get<2>(t2);
    }
};
class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &s,vector<int> &e){
        
        vector<tuple<int,int,int>>v;
        
        for(int i=0;i<N;i++){
            v.push_back(make_tuple(i+1,s[i],e[i]));
        }
        
        
        sort(v.begin(),v.end(),cmp());
        
        vector<int>result;
        
        auto last=v[0];
        
        result.push_back(get<0>(last));
        
        for(int i=1;i<N;i++){
            if(get<2>(last) < get<1>(v[i])){
                last=v[i];
                result.push_back(get<0>(v[i]));
            }
        }
        sort(result.begin(),result.end());
        
        return result;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends