#include <iostream>
using namespace std;

class Circular_Queue
{
private:
    int front;
    int rear;
    int *arr;
    int size;

public:
    Circular_Queue(int size)
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
        if ((rear + 1) % size == front)
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
            arr[rear] = val;
            return;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = val;
        }
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
        }
        else
        {
            arr[front] = -1;
            front = (front + 1) % size;
        }
    }
    int QueueSize()
    {
        if (front == -1 && rear == -1)
        {
            return 0;
        }
        return (rear - front + 1);
    }
    void printQueue()
    {
        for (int i = 0; i <size; i++)
        {
            if(arr[i]==-1){
                continue;
            }
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Circular_Queue c(3);

    c.enqueue(1);
    c.enqueue(1);
    c.printQueue();
}