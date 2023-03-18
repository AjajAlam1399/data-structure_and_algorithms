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
        this->heap_size = capcity;
        Harr = new int[capcity];
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
    void heapsort()
    {
        int temp[capcity];
        for (int i = 0; i < capcity; i++)
        {
            temp[i] = Extract_min();
            cout << temp[i] << " ";
        }
    }
    void getUnsortedArray()
    {
        for (int i = 0; i < heap_size; i++)
        {
            int num;
            cin >> num;
            Harr[i] = num;
        }
    }
};

int main()
{
    int s;
    cin >> s;
    MinHeap h(s);
    h.getUnsortedArray();

    // first time hippfy

    for (int i = s / 2 - 1; i >= 0; i--)
    {
        h.hippyfiy(i);
    }

    h.heapsort();
}