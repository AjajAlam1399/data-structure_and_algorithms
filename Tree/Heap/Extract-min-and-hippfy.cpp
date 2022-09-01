#include <bits/stdc++.h>
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
    int left(int i)
    {
        return (2 * i + 1);
    }
    int right(int i)
    {
        return (2 * i + 2);
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

        while (i != 0 && Harr[parent(i)] > Harr[i])
        {
            swap(Harr[i], Harr[parent(i)]);
            i = parent(i);
        }
    }
    void hippyfiy(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap_size && Harr[l] < Harr[i])
        {
            smallest = l;
        }
        if (r < heap_size && Harr[r] < Harr[smallest])
        {
            smallest = r;
        }
        if (smallest != i)
        {
            swap(Harr[i], Harr[smallest]);
            hippyfiy(smallest);
        }
    }
    int Extract_min()
    {
        if (heap_size == 0)
        {
            return INT_MIN;
        }
        if (heap_size == 1)
        {
            heap_size--;
            return Harr[0];
        }
        int root = Harr[0];
        Harr[0] = Harr[heap_size - 1];
        heap_size--;
        hippyfiy(0);
        return root;
    }
    void print()
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << Harr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MinHeap h(5);
    for (int i = 1; i <= 5; i++)
    {
        int num;
        cin >> num;
        h.insert(num);
    }
    h.print();
    cout<<h.Extract_min()<<endl;
    h.print();
}