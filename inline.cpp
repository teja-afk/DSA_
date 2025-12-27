#include <iostream>
using namespace std;

inline int cube(int n){
  return n*n*n;
}

int main() {

  int num = 3;
  cout << "Cube of " << num << " is : " << cube(num) << endl;

  return 0;
}
