#include <iostream>
using namespace std;

class stack
{
private:
    int top;
    int *arr;
    int size;

public:
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
        for (int i = 0; i < size; i++)
        {
            arr[i] = -1;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack UnderFlow !" << endl;
            return;
        }
        arr[top] = -1;
        top--;
    }
    int Stacksize()
    {
        return (top + 1);
    }
    int Stacktop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty !" << endl;
            return -1;
        }
        return arr[top];
    }
    void printStack()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    stack s1(3);

    s1.push(1);
    s1.push(2);
    cout<<s1.Stacktop()<<endl;
    s1.printStack();
}