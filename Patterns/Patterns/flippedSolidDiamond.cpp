#include<iostream>
using namespace std;
int main(){
  int n;
  cin >> n;

  //first half
  for(int row = 0; row < n; row++){
    //inverted Pyramid 1
    for(int col = 0; col < n-row; col++){
      cout << "*";
    }
    //full Pyramid 1
    for(int col = 0; col < 2 * row + 1; col++){
      cout << " ";
    }
    //inverted pyramid 2
    for(int col = 0; col < n-row; col++){
      cout << "*";
    }
  }

  //second half
  for(int row = 0; row < n; row++){
    //inverted Pyramid 1
    for(int col = 0; col <row+1; col++){
      cout << "*";
    }
    //full Pyramid 2
    for(int col = 0; col < 2*n-2*row-1; col++){
      cout << " ";
    }
    //inverted pyramid 2
    for(int col = 0; col <row+1; col++){
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}
