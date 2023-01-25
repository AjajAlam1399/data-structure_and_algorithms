#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        if(k==1){
            return funk1(nums);
        }
        
        int countodds=0;
        int countoddb=0;

        int is,ib,j;
        is=ib=j=-1;

        int ans=0;

      
        while(true){

            bool f1,f2,f3;
            f1=f2=f3=false;

            while(ib<n-1){
                f1=true;
                ib++;
                if(nums[ib]%2!=0){
                    countoddb++;
                }
                if(countoddb==k+1){
                    countoddb--;
                    ib--;
                    break;
                }
            }

            while(is<ib){
                f2=true;
                is++;
                if(nums[is]%2!=0){
                    countodds++;
                }
                if(countodds==k){
                    countodds--;
                    is--;
                    break;
                }
            }

            while(j<is){
                f3=true;
                if(countodds==k-1 && countoddb==k){
                    ans+=ib-is;
                }
                j++;
                if(nums[j]%2!=0){
                    countodds--;
                    countoddb--;
                }

                if(countodds<k-1 || countoddb<k){
                    break;
                }
            }

            if(!f1 && !f2 && !f3){
                break;
            }
        }

        return ans;
    }
    int funk1(vector<int>& nums){
        int i,j,n;
        i=j=-1;
        n=nums.size();

        int countodd=0;
        int ans=0;

        

        while(true){
            bool f1,f2;
            f1=f2=false;
            int cnt=0;
            while(i<n-1){
                f1=true;
                i++;
                if(nums[i]%2!=0){
                    countodd++;
                }
                if(countodd==1 && nums[i]%2==0){
                    cnt++;
                }
                if(countodd==2){
                    countodd--;
                    i--;
                    break;
                }
            }

            while(j<i){
                f2=true;
                if(countodd==1){
                    ans+=1+cnt;
                }
                j++;
                if(nums[j]%2!=0){
                    countodd--;
                }
                if(countodd==0){
                    cnt=0;
                    break;
                }
            }

            if(!f1 && !f2){
                break;
            }
        }

        return ans;
    }
};