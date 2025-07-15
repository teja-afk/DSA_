#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

// kth smallest element

int kthSmallestElement(int arr[], int n, int k){
    sort(arr, arr+n); // TC : O(nlog)
    return arr[k-1];
}

int main() {

  int arr[] = {10, 5, 50, 23, 17, 8, 21, 57};
  //            5  8  10  17  21  23 50  57
  //                   k
  int n = 8;
  int k = 3;


  


  // int ans = kthSmallestElement(arr, n, k);  //BRUTE FORCE TC : O(nlogn) SC : O(n)
  // cout << "Kth Smallest no : " << ans << endl; 

  // priority_queue<int, vector<int>, greater<int>>minHeap; TC : O(n) SC : O(1)
  // minHeap.push(10);
  // minHeap.push(5);
  // minHeap.push(50);
  // minHeap.push(23);
  // minHeap.push(17);
  // minHeap.push(8);
  // minHeap.push(21);
  // minHeap.push(57);
  // int t = k-1;
  // while(t--){
  //   minHeap.pop();
  // }
  // cout << "kth smallest no : "<< minHeap.top() << endl;

  // MIN HEAP
  //             <dataType, container, comparator>
  // priority_queue<int, vector<int>, greater<int>>pq; // MIN HEAP
  
  // pq.push(10);
  // pq.push(5);
  // pq.push(30);
  // pq.push(20);

  // cout << pq.top() << endl;

  // pq.pop();
  // cout << pq.top() << endl;


  // create
  // priority_queue<int>pq; // default MAX HEAP
  // // insert
  // pq.push(10);
  // pq.push(5);
  // pq.push(30);
  // pq.push(15);

  // // access front element
  // cout << pq.top() << endl;
  
  // // removal
  // pq.pop();
  // cout << pq.top() << endl;
  // pq.pop();
  // cout << pq.top() << endl;
  // pq.pop();
  // pq.pop();
  
  // cout << "Size : "<< pq.size() << endl;
  // pq.pop();
  
  // if(!pq.empty()){
  //   cout << "pq is not empty " << endl;
  // }

  return 0;
}