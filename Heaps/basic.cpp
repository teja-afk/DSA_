#include<iostream>
using namespace std;

class Heap{
public:
  int* arr;
  int capacity;
  int index;

  Heap(int n) {
    this->capacity = n;
    arr = new int[n];
    index = 0;
    // jab bhi mujhe insert karna hoga, tab index+1 karke insert krdena
  }

  void printHeap() {
    for(int i=0; i<capacity; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  void insert(int val) { // inserion TC : O(logn)
    if(index == capacity - 1){
      cout << "Overflow" << endl;
      return;
    }
    // agar jagah available hai
    index++; //  pehle index increment to avoid filling in zero position
    arr[index] = val; 
    // now put value at right position
    // by comparing with parent node
    int i = index; // original heap ke index ko copy karlenge
    
    while(i > 1){
      int parentIndex  = i / 2;

      if(arr[parentIndex] < arr[i]){
        swap(arr[parentIndex], arr[i]);
        i = parentIndex;
      }else{
        // parent already bada hai, no need to do anything
        break;
      }
    }
  }

  void deleteFromHeap() { // deletion TC : O(logn)
    // replacement
    swap(arr[1], arr[index]);
    // size decrease
    index--;
    // heapify
    // heapify(arr, index, 1);  // element ko apne correct position pe lao
  }
};

// heapify value present at currIndex
void heapify(int* arr, int n, int currIndex) {

  int i = currIndex;
  int leftIndex = 2*i;
  int rightIndex = 2*i+1;

  int largestKaIndex = i;
  
  if(leftIndex < n && arr[leftIndex] > arr[largestKaIndex]) {
    largestKaIndex = leftIndex;
  }

  if(rightIndex < n && arr[rightIndex] > arr[largestKaIndex]) {
    largestKaIndex = rightIndex;
  }

  if(largestKaIndex != i){
    swap(arr[i], arr[largestKaIndex]);
    i = largestKaIndex;
    heapify(arr, n, i);
  }
}

void buildHeap(int* arr, int n) {
  for(int i = n/2; i>0; i--) {
    heapify(arr, n, i);
  }
}

void heapSort(int* arr, int n) {
  // n -> size
  while(n > 1) {
    // delete root element, swap the root element with last element
    swap(arr[1], arr[n-1]);
    // delete the last element
    n--;
    heapify(arr, n, 1);
  }
}

int main() {

  int arr[] = {-1, 5, 7, 9, 1, 3, 10, 8, 4};
  int n = 9;

  buildHeap(arr, n);

  cout << "Printing Heap : "<< endl;
  for(int i=1; i<n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl << endl;
  
  // heapSort(arr, n);
  
  // cout << "Printing HeapSort : "<< endl;
  // for(int i=1; i<n; i++) {
  //   cout << arr[i] << " ";
  // }
  // cout << endl;

  // Heap pq(10);
  // 50 40 30 10 20
  // pq.insert(10);
  // pq.insert(20);
  // pq.insert(30);
  // pq.insert(40);
  // pq.insert(50); 
  // pq.printHeap();

  return 0;
}