#include <iostream>
#include <math.h>
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
};

int main()
{
}