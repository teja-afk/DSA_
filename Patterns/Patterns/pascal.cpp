#include<iostream>
#include<vector>
using namespace std;

int main(){

  int numRows = 20;

  vector<vector<int>> a(numRows);
  cout << "Creating pascal triangle....\n";
  for (int i = 0; i < numRows; i++) {
    a[i] = vector<int>(i + 1, 1);  // Initialize row with (i+1) elements, all 1s
    for (int j = 1; j < i; j++) {
      a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    }
  }
  cout << "Pascal triangle created Sucessfully.\n\n";
  
  cout << "Printing pascal triangle : \n";
  for(int i=0; i<a.size(); i++){
    for(int j=0; j<a[i].size(); j++){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}