#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        int ans=1;
        int m_bit=0;
        int mod=pow(10,9)+7;
        for(int i=2;i<=n;i++){
            if((i&(i-1))==0){
                m_bit++;
            }
            ans=(ans<<(m_bit+1));
            ans=(ans|i)%mod;
        }
        
        return ans%mod;
    }
};