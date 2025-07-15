#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Info{
  public:
    int data;
    int rIndex;
    int cIndex;
    
    //   data, rIndex, cIndex
    Info(int x, int y, int z){
      data = x;
      rIndex = y;
      cIndex = z;
    }
};

class compare{
  public:
    bool operator()(Info* a, Info* b){
      return a->data > b->data;
    }
};

// Function to merge k sorted arrays.
vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    
  priority_queue<Info*, vector<Info*>, compare>pq;
  vector<int>ans;
  
  int totalRows = arr.size();
  int totalColumns = arr[0].size();
  
  // STEP 1 : process first k elements in MIN HEAP
  
  for(int row = 0; row<totalRows; row++) {    // 1, 2, 3
    int element = arr[row][0];              // 4, 5, 6
    Info* temp = new Info(element, row, 0); // 7, 8, 9
    pq.push(temp);
  }
  // MIN HEAP mei zeroth column ka first elements store hai // 1, 4, 7
  
  while(!pq.empty()) {
    Info* front = pq.top(); pq.pop();
    
    int frontdata = front->data;
    int front_rIndex = front->rIndex;
    int front_cIndex = front->cIndex;
    
    // STEP 2 : insert into ans
    ans.push_back(frontdata);
    
    // STEP 3 : process next column index
    if(front_cIndex+1 < totalColumns) {
      int element = arr[front_rIndex][front_cIndex+1];
      Info* temp = new Info(element, front_rIndex, front_cIndex+1);
      pq.push(temp);
    }
  }
  return ans;
}

void printArray(vector<int>arr){
  for(int i=0; i<arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  vector<vector<int>>arr = {{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};
  int K = 3;

  vector<int>ans = mergeKArrays(arr, K);

  cout << "Printing Merged Sorted Array : ";
  printArray(ans);


  return 0;
}