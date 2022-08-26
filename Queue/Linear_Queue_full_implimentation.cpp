#include <iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int *arr;
    int size;

public:
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = -1;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (rear == size - 1)
            return true;

        else
            return false;
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is overflowing !" << endl;
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is underflowing !" << endl;
            return;
        }
        else if (rear == front)
        {
            arr[front] = -1;
            rear = front = -1;
            return;
        };
        arr[front] = -1;
        front++;
    }
    int QueueSize()
    {
        if(front==-1 && rear==-1){
            return 0;
        }
        return (rear - front + 1);
    }
    void printQueue()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q1(3);
    cout<<q1.QueueSize();
    // q1.printQueue();
}