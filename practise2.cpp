#include <iostream>
using namespace std;

class Vehicle {
public:
  int wheels;
  int doors;
  int engineCylinders;

  void isEngineRunning(){
    cout << "Vehicle engine is running" << endl;
  }

};

class Car: public Vehicle{
public:
  Car(int w, int d, int c){
    this->wheels = w;
    this->doors = d;
    this->engineCylinders = c;
  }
};

class PickUp: public Vehicle {
public:
  PickUp (int wheelCount, int doors, int cylinders) {
    this->wheels = wheelCount;
    this->doors = doors;
    this->engineCylinders = cylinders;
  }

  void getDetails(){
    cout << "PickUp has " << wheels << " wheels." <<  endl;
    cout << "PickUp has " << doors << " doors." <<  endl;
    cout << "PickUp is " << engineCylinders << " cylinders engine." <<  endl;
  }

};

int main() {
  // Vehicle v1;
  // PickUp p1(4, 2, 6);
  // p1.getDetails();

  Car c1(4, 4, 3);
  // c1.getDetails();
  c1.isEngineRunning();

  return 0;
}
