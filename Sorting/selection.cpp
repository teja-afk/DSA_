#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>v){
  for(int i=0; i<v.size(); i++){
    cout << v[i] <<" ";
  }cout << endl;
}

void selectionSortInc(vector<int>&v){
  int n=v.size();
  for(int i=0; i<n-1; i++){
    int minIndex = i;
    for(int j=i+1; j<n; j++){
      if(v[j] < v[minIndex]){
        minIndex = j;
      }
    }
    swap(v[i], v[minIndex]);
  }
}

void selectionSortDec(vector<int>&v){
  int n=v.size();
  for(int i=0; i<n-1; i++){
    int maxIndex = i;
    for(int j=i+1; j<n; j++){
      if(v[j] > v[maxIndex]){
        maxIndex = j;
      }
    }
    swap(v[i], v[maxIndex]);
  }
}


int main(){

  vector<int> v = {77, 66, 55, 44, 33, 22, 11};
  
  print(v);

  // Increasing order selection sort
  selectionSortInc(v);
  print(v);

  // Decreasing order selection sort
  selectionSortDec(v);
  print(v);

  return 0;
}