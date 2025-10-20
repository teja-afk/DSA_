#include<iostream>
#include<vector>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
  int row = 0, col = 0;
  bool up = true;
  int m = mat.size();
  int n = mat[0].size();
  vector<int>arr;

  while(row < m && col < n){
    if(up){ // if diagonal is moving up
      while(row > 0 && col < n-1){
        arr.push_back(mat[row][col]);
        row--;
        col++;
      }
      arr.push_back(mat[row][col]);
      if(col == n-1){
        row++;
      }else{
        col++;
      }
    }else{ // moving down
      while(col > 0 && row < m-1){
        arr.push_back(mat[row][col]);
        row++;
        col--;
      }
      arr.push_back(mat[row][col]);
      if(row == m-1){
        col++;
      }else{
        row++;
      }
    }
    up =! up;
  }
  return arr;
}


int main(){

  vector<vector<int>>mat = {  {1, 2, 3}, 
                              {4, 5, 6},
                              {7, 8, 9} };

  vector<int> result = findDiagonalOrder(mat);
  
  for(int i : result) {
      cout << i << " ";
  }
  return 0;
}
