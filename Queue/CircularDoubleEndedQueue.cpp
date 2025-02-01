#include<iostream>
using namespace std;

class DeCircularQueue{
public:
    int *arr;
    int n;
    int front;
    int rear;

    DeCircularQueue(int size){
        arr = new int[size];
        n = size;
        front = -1; 
        rear = -1; 
    }

    void pushFront(int val){
        // 4 cases: Overflow, Single Element, Circular Nature, Normal
        if((front == 0 && rear == n - 1) || (rear == front - 1)){
            cout << "Overflow" << endl;
        }else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[front] = val;
        }else if(front == 0){
            front = n - 1;
            arr[front] = val;
        }else{
            front--;
            arr[front] = val;
        }
    }

    void pushBack(int val){
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

    int popFront(){
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

    void popBack(){
        // 4 case: Underflow, Single Element, Circular Nature, Normal
        if(front == -1 && rear == -1){
            cout << "Underflow" << endl;
        }else if(front == rear){
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }else if(rear == 0){
            arr[rear];
            rear = n - 1;
        }else{
            arr[rear] = -1;
            rear--;
        }
    }

    void print(){
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }

    

};

int main(){

    DeCircularQueue q(5);
    
    q.pushFront(10);
    q.print();
    q.pushFront(50);
    q.print();
    q.pushFront(30);
    q.print();
    q.pushBack(20);
    q.print();
    q.pushBack(35);
    q.print();
    q.popFront();
    q.print();
    q.popFront();
    q.print();
    q.popFront();
    q.print();
    q.popBack();
    q.print();
    q.popBack();
    q.print();
    

    return 0;
}