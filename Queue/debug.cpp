#include<iostream>
#include<vector>
using namespace std;

// // 1. Circular Queue using array
// class MyCircularQueue {
//     int* arr;
//     int qfront;
//     int rear;
//     int size;
// public:
//     MyCircularQueue(int n) {
//         arr = new int[n];
//         rear = -1;
//         qfront = -1;
//         size = n;
//     }
//     bool enQueue(int value) {
//         if (isFull()) {
//             return false;
//         }
//         if (isEmpty()) {
//             qfront = rear = 0;
//         } else {
//             rear = (rear + 1) % size;
//         }
//         arr[rear] = value;
//         return true;
//     }
//     bool deQueue() {
//         if (isEmpty()) {
//             return false;
//         }
//         if (qfront == rear) {
//             qfront = rear = -1;
//         } else {
//             qfront = (qfront + 1) % size;
//         }
//         return true;
//     }
//     int Front() {
//         if (isEmpty()) {
//             return -1;
//         }
//         return arr[qfront];
//     }
//     int Rear() {
//         if (isEmpty()) {
//             return -1;
//         }
//         return arr[rear];
//     }
//     bool isEmpty() {
//         return qfront == -1;
//     }
//     bool isFull() {
//         return (qfront == 0 && rear == size - 1) || (qfront == rear + 1);
//     void print(){
//         for(int i=0; i<size; i++){
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
// };

// 4.
// A circular array means the end of the array connects to the beginning of the array.
// int maxSubarraySumCircular(vector<int>& nums) {
//     const int n = nums.size();
//     vector<int> rightMax(n);
//     rightMax[n - 1] = nums[n - 1];
//     int suffixSum = nums[n - 1];
//     for (int i = n - 1; i >= 0; --i) {
//         suffixSum += nums[i];
//         rightMax[i] = max(rightMax[i + 1], suffixSum);
//     }
//     int maxSum = nums[0];
//     int specialSum = nums[0];
//     int curMax = 0;
//     int prefixSum = 0;
//     for (int i = 0; i < n; ++i) {
//         // this is kadane's algorithm
//         curMax = max(curMax, 0) + nums[i];
//         maxSum = max(maxSum, curMax);
//         prefixSum += nums[i];
//         if (i + 1 < n) {
//             specialSum = max(specialSum, prefixSum + rightMax[i + 1]);
//         }
//     }
//    return max(maxSum, specialSum);
// }

// 5.
class MyCircularDeque {
    int *arr;
    int size;
    int front;
    int rear;
public:
    MyCircularDeque(int k) {
        size=k;
        arr = new int [size];
        front = -1;
        rear = -1;
    }
    bool insertFront(int value) {
         if(isFull()){
            cout << "Queue is full" << endl;
            return false;
        }
         if(front==-1 && rear==-1){
            front = rear = 0;
        }
        else if(front == 0){  
           front = size-1;
        }
        else{
            front--;
        }
        arr[front]=value;
        return true;
    }
    bool insertLast(int value) {
          if(isFull()){
            cout << "Queue is full " << endl;
            return false;
        }
         if(front==-1 && rear==-1){
            front = rear = 0;
        }
        else{  
            rear = (rear+1)%size;
        }
        arr[rear] = value;
        return true;
    }
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        int ans = arr[front];
        arr[front] = -1;
         if (front == rear){
            front = rear = -1;
        }
        else {
            front = (front+1)%size;
        }
        return true;
    }
    bool deleteLast() {
         if(isEmpty()){
            return false;
        }
        int ans=arr[rear];
        arr[rear]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
        return true;
    }
    int getFront() {
         if(isEmpty()){
            return -1;
        }
        else{
            return arr[front];
        }
    }
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[rear];
        }
    }
    bool isEmpty() {
        if(front==-1 && rear==-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull() {
        if((rear+1)%size==front){
            cout << "Queue is full" << endl;
            return true;
         } else {
            return false;
         }
    }
};


int main(){




    // vector<int>nums(5);
    // nums.push_back(-1);
    // nums.push_back(3);
    // nums.push_back(6);
    // nums.push_back(1);

    // cout << maxSubarraySumCircular(nums) << endl;


    // MyCircularQueue cq(5);
    // cq.enQueue(5);
    // cq.enQueue(6);
    // cq.enQueue(7);
    // cq.enQueue(8);
    // cout << "Front Element: " << cq.Front() << endl;
    // cout << "DeQueue: " << cq.deQueue() << endl;
    // cout << "DeQueue: " << cq.deQueue() << endl;
    // cout << "DeQueue: " << cq.deQueue() << endl;
    // cout << "DeQueue: " << cq.deQueue() << endl;
    // cout << "DeQueue: " << cq.deQueue() << endl;
    // cq.print();
    return 0;
}