#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* children[26];
    node(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};


int countDistinctSubstring(string s)
{
    //Your code here
    
    node* head=new node();
    int ans=1;
    for(int i=0;i<s.size();i++){
        node* temp=head;
       for(int j=i;j<s.size();j++){
           if(!temp->children[s[j]-'a']){
               temp->children[s[j]-'a']=new node();
               ans++;
           }
           temp=temp->children[s[j]-'a'];
  }
    }
    return ans;
    
}