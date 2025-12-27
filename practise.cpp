#include<iostream>
#include<vector>
using namespace std;

// 1         1
// 2        1 1
// 3       1 2 1
// 4      1 3 3 1
// 5     1 4 6 4 1
// 6    1 5 10 10 5 1
// 7   1 6 15 20 15 6 1

int main(){


  int numRows = 5;

  vector<vector<int>> a(numRows);
  cout << "Creating pascal triangle ";
  for (int i = 0; i < numRows; i++) {
    a[i] = vector<int>(i + 1, 1);  // Initialize row with (i+1) elements, all 1s
    for (int j = 1; j < i; j++) {
      a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    }
  }

  cout << "Printing pascal triangle : \n";
  for(int i=0; i<a.size(); i++){
    for(int j=0; j<a[i].size(); j++){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
