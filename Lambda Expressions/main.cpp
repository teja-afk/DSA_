#include<iostream>
using namespace std;
// introduce in C++ 11
// SYNTAX
// [capture](parameter)
// {
//   function body
// }

int main(){

  auto add = [](int a, int b)
  {
    return a + b;
  };

  cout << add(3, 5) << endl;

  return 0;
}
