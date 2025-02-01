#include<iostream>
using namespace std;
// building Single Ended Queue from scratch
// TC : (1), SC : O(n)

class Queue{
private:
    int *arr;
    int n; // size
    int front;
    int rear;

public:
    Queue(int size){
        arr = new int[size];
        n = size;
        front = -1;
        rear = -1;
    }

    void push(int val){
        // Overflow
        if(rear == n - 1){
            cout << "Overflow" << endl;
        }
        // First Element insertion
        else if(front == -1 && rear == -1){
            rear++;
            arr[rear] = val;
            front++;
        }
        // Normal insertion
        else{
            rear++;
            arr[rear] = val;
        }
    }

    void pop(){
        // Underflow
        if(front == -1 && rear == -1){
            cout << "Underflow" << endl;
        }
        // Single Element
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // Normal
        else{
            arr[front] = -1;
            front++;
        }
    }

    int getFront(){
        if(front == -1){
            cout << "Queue is Empty" << endl;
        }else{
            return arr[front];
        }
    }

    int getRear(){
        if(rear == -1){
            cout << "Queue is Empty" << endl;
        }else{
            return arr[rear];
        }
    }

    int getSize(){
        if(front == -1 && rear == -1){
            return 0;
        }else
            return rear - front + 1;
    }


    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }else{
            return false;
        }
    }

};

int main(){

    Queue q(5);

    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // // cout << q.getSize() << endl;
    // // q.push(50);
    // // cout << q.getFront() << endl;
    // // cout << q.isEmpty() << endl;
    // // cout << q.getRear() << endl;
    // q.pop();
    // cout << q.getRear() << endl;
    // cout << q.getFront() << endl;
    // q.pop();
    // q.pop();
    // q.pop();
    // cout << q.getSize() << endl;
    // q.pop();
    // q.pop();
    // cout << q.getSize() << endl;


    return 0;
}
