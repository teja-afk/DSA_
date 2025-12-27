#include <iostream>
using namespace std;

class Car{
public:
  string brand;

  // Car(string b){
  //   this->brand = b;
  // }

  void display(){
    cout << "The Car brand is : " << brand << endl;
  }
};

int main() {

  Car c1;
  c1.display();

  return 0;
}
