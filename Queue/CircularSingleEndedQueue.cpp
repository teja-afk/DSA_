#include <iostream>
using namespace std;

class CircularQueue
{
public:
    int *arr;
    int n;
    int front;
    int rear;

    CircularQueue(int size)
    {
        arr = new int[size];
        n = size;
        front = -1;
        rear = -1;
    }

    void push(int val)
    {
        // 4 case: Overflow, first element, circular nature, normal flow
        if ((front == 0 && rear == n - 1) || (rear == front - 1))
        {
            cout << "Overflow" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else if (rear == n - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    void pop()
    {
        // 4 cases: Underflow, single element, circular nature, normal flow
        if (front == -1 && rear == -1)
        {
            cout << "Underflow" << endl;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            rear = -1;
            front = -1;
        }
        else if (front == n - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    int getFront()
    {
        if (front == -1)
        {
            cout << "Queue is empty";
        }
        else
        {
            return arr[front];
        }
    }

    int getSize()
    {
        if (front == -1 && rear == -1)
        {
            return 0;
        }
        else if (rear >= front)
        {
            return abs(rear - front) + 1;
        }
        else
        {
            return n - front + rear + 1;
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

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    CircularQueue q(5);

    q.push(10);
    q.print();
    q.push(20);
    q.print();
    q.push(30);
    q.print();
    q.push(40);
    q.print();
    q.push(50);
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.push(20);
    q.print();
    cout << q.getSize() << endl;
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    cout << q.getSize() << endl;
    return 0;
}