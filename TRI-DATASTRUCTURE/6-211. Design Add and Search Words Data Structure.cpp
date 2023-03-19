#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    Node* children[26];
    bool isterminal;

    Node(char data){
        this->data=data;
        isterminal=false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class WordDictionary {
    Node* root;

    void Add(Node* root,string word){

        if(word.size()==0){
            root->isterminal=true;
            return ;
        }

        int index=word[0]-'a';
        Node* temp;
        if(!root->children[index]){
            temp=new Node(word[0]);
            root->children[index]=temp;
        }
        temp=root->children[index];
        Add(temp,word.substr(1));
    }
    bool serachW(Node* root,string word){

        if(word.size()==0){
            return root->isterminal;
        }

        if(word[0]=='.'){
            for(int i=0;i<26;i++){
                if(root->children[i]){
                   if(serachW(root->children[i],word.substr(1))){
                       return true;
                   }
                }
            }
        }
        else{
            int index=word[0]-'a';
            Node* temp;
            if(root->children[index]){
                if(serachW(root->children[index],word.substr(1))){
                    return true;
                }
            }
            else{
                return false;
            }
        }
        return false;
    }
public:
    WordDictionary() {
        root=new Node('0');
    }
    
    void addWord(string word) {
        Add(root,word);
        
    }
    
    bool search(string word) {
        return serachW(root,word);
    }
};