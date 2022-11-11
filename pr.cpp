#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* childern[26];
    bool isterminal;

    TrieNode(char data){
        this->data=data;
        for(int i=0;i<26;i++){
            childern[i]=NULL;
        }
        isterminal=false;
    }
};

class trie{
    TrieNode* root;

    //inserting
    void insertUtil(TrieNode* r,string str){

        // base case

        if(str.size()==0){
            r->isterminal=true;
            return ;
        }

        TrieNode* child;

        int index=str[0]-'A';   // assuming inseted letter in uppercase

        if(r->childern[index]!=NULL){
            child=r->childern[index];
        }
        else{
            child=new TrieNode(str[0]);
            r->childern[index]=child;
        }
        insertUtil(child,str.substr(1));
    }
    bool searchUtil(TrieNode* r,string str){

        if(str.size()==0){
            return r->isterminal;
        }

        int index=str[0]-'A';
        TrieNode* child;
        if(r->childern[index]!=NULL){
            child=r->childern[index];
        }
        else{
            return false;
        }
        return searchUtil(child,str.substr(1));
    }
    TrieNode* removeUtil(TrieNode* r,string str){
        if(str.size()==0){
            r->isterminal=false;
            return NULL;
        }

        int index=str[0]-'A';
        TrieNode* child;
        if(r->childern[index]!=NULL){
            child=r->childern[index];
        }
        return removeUtil(child,str.substr(1));
    }
    public:

    trie(){
        root=new TrieNode('\0');
    }

    void insert(string str){
        insertUtil(root,str);
    }

    bool search(string str){

        return searchUtil(root,str);
    }

    void remove(string str){
        removeUtil(root,str);
    }
};

int main(){
    trie t;

    t.insert("AJAJ");

    cout<<t.search("AJAJ");
    t.remove("AJAJ");
    cout<<endl;
    cout<<t.search("AJAJ");


    t.insert("CAR");
    cout<<endl<<t.search("CAR");
}

