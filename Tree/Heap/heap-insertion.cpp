#include<bits/stdc++.h>
using namespace std;

class MinHeap
{
public:
    int *Harr;
    int capcity;
    int heap_size;

    MinHeap(int capcity)
    {
        this->capcity = capcity;
        this->heap_size = 0;
        Harr = new int[capcity];
    }
    void linearSearch(int val)
    {
        for (int i = 0; i < heap_size; i++)
        {
            if (Harr[i] == val)
            {
                cout << "Value found " << endl;
                return;
            }
        }
        cout << "Value is not found !" << endl;
    }
    int height()
    {
        return ceil(log2(heap_size + 1)) - 1;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    void insert(int val)
    {
        if (heap_size == capcity)
        {
            cout << "Heap is overflow !" << endl;
            return;
        }
        heap_size++;
        int i = heap_size - 1;
        Harr[i] = val;

        while (i != 0 && Harr[parent(i)]>Harr[i]){
            swap(Harr[i],Harr[parent(i)]);
            i=parent(i);
        }
    }
};

int main()
{
}