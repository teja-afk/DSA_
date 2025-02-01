#include<iostream>
using namespace std;
// building Doubly Ended Queue from scratch
// TC : (1), SC : O(n)

class Deque{
private:
    int *arr;
    int n;
    int front;
    int rear;

public:
    Deque(int size){
        arr = new int[size];
        n = size;
        front = -1;
        rear = -1;
    }

    void pushFront(int val){
        // Overflow
        if(front == 0){
            cout << "Overflow"<< endl;
        }
        // First Element insertion
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[front] = val;
        }
        // Normal
        else{
            front--;
            arr[front] = val;
        }
    }

    void popBack(){
        // Underflow
        if(front == -1 && rear == -1){
            cout << "Underflow" << endl;
        }
        // Single Element deletion
        else if(front == rear){
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        // Normal
        else{
            arr[rear] = -1;
            rear--;
        }
    }

    void pushBack(int val){
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

    void popFront(){
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

    // printing deque
    void print(){
        for(int i=0; i<n; i++){
            cout << arr[i] <<" ";
        }cout << endl;
    }

};


int main(){

    Deque dq(5);

    dq.pushFront(10);
    dq.print();
    dq.pushFront(20);
    dq.print();
    dq.pushBack(30);
    dq.print();
    dq.pushBack(40);
    dq.print();
    dq.pushBack(50);
    dq.print();
    dq.pushBack(60);
    dq.print();

    dq.popFront();
    dq.print();
    dq.popFront();
    dq.print();
    dq.popBack();
    dq.print();
    dq.popBack();
    dq.print();
    dq.popBack();
    dq.print();


    return 0;
}