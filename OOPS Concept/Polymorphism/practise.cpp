#include<iostream>
using namespace std;

class A{
public:
  int a, b;

  void operator+ (A &obj){
    int val1 = this->a;
    int val2 = obj.a;
    cout << val2-val1 << endl;
  }

};

int main(){

  A obj1, obj2;
  obj1.a = 7;
  obj2.a = 4;
  obj2 + obj1;


  return 0;
}

