#include <bits/stdc++.h>
using namespace std;

class Hashmap
{
    vector<list<pair<int, int>>> map;
    int size = 50;
public:
    Hashmap()
    {
        map.resize(size); // intializing all element with 0
    }
    int Hashing(int key)
    {
        return key % size;
    }
    list<pair<int,int>>::iterator search(int key){
        int i=Hashing(key);
        for(auto it=map[i].begin();it!=map[i].end();it++){
            if(it->first==key){
                return it;
            }
        }
        return map[i].end();
    }
    void put(int key, int value)
    {
        int i=Hashing(key);
        auto it=search(key);
        if(it!=map[i].end()){
            it->second=value;
            return;
        }
        map[i].push_back(make_pair(key,value));

    }
    int get(int key)
    {
        int i=Hashing(key);
        auto it=search(key);
        if(it!=map[i].end()){
            return it->second;
        }
        return -1;
    }
    void remove(int key)
    {
        int i=Hashing(key);
        auto it=search(key);
        if(it==map[i].end()){
            return ;
        }
        map[i].erase(it);
    }
};