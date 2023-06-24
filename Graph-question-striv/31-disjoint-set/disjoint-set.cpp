#include<bits/stdc++.h>
using namespace std;

class disjoint_set{
    vector<int>parent,rank,size;
    public:
    disjoint_set(int v){
        parent.resize(v+1);
        rank.resize(v+1,0);
        size.resize(v+1,1);
        for(int i=0;i<=v;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        parent[x]=find(parent[x]);
    }
    void unionByRank(int x,int y){
        int rootx=find(x);
        int rooty=find(y);
        if(rootx==rooty){
            return ;
        }
        if(rank[rootx]>rank[rooty]){
            parent[rooty]=rootx;
        }
        else if(rank[rootx]<rank[rooty]){
            parent[rootx]=rooty;
            
        }
        else{
            parent[rootx]=rooty;
            rank[rooty]++;
        }
    }
    void unionBySize(int x,int y){
        int rootx=find(x);
        int rooty=find(y);
        if(rootx==rooty){
            return ;
        }
        if(size[rootx]<size[rooty]){
            parent[rootx]=rooty;
            size[rooty]+=size[rootx];
        }
        else{
            parent[rooty]=rootx;
            size[rootx]+=size[rooty];
        }
    }
};