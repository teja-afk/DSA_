#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    // Attributes
    string name;
    string model;
    int noOfTyres;

    // GETTER
    string getName()
    {
        return this->name;
    }

public:
    // Constructor
    Vehicle(string _name, string _model, int _noOfTyres)
    {
        cout << "I am inside Vehicle constructor" << endl;
        this->name = _name;
        this->model = _model;
        this->noOfTyres = _noOfTyres;
    }

public:
    // Behaviours
    void start_engine()
    {
        cout << "Engine is Starting : " << name << " " << model << endl;
    }

    void stop_engine()
    {
        cout << "Engine is Stopping : " << name << " " << model << endl;
    }

    ~Vehicle(){
        cout << "I am inside Vehicle Destructor " << endl;
    }
};

class Car : public Vehicle
{
public:
    // Attributes
    int noOfDoors;
    string transmissionType;

    // Constructor
    Car(string _name, string _model, int _noOfTyres, int _noOfDoors, string _transmissionType) : Vehicle(_name, _model, _noOfTyres)
    {
        cout << "I am inside Car constructor" << endl;
        this->noOfDoors = _noOfDoors;
        this->transmissionType = _transmissionType;
    }

    // Behaviours
    void startAC()
    {
        cout << "AC has started of " << getName() << endl;
    }

    ~Car(){
        cout << "I am inside Car Destructor " << endl;
    }
};

class MotorCycle : public Vehicle
{

protected:
    string handleBarStyle;
    string suspensionType;

public:
    MotorCycle(string _name, string _model, int _noOfTyres, string _handleBarStyle, string _suspensionType) : Vehicle(_name, _model, _noOfTyres)
    {
        cout << "I am inside Motorcycle constructor " << endl;
        this->handleBarStyle = _handleBarStyle;
        this->suspensionType = _suspensionType;
    }

    void wheelie()
    {
        cout << "Wheelie kar rahi hai " << name << endl;
    }

    ~MotorCycle(){
        cout << "I am inside MotorCycle Destructor " << endl;
    }
};


class Employee{
private:
  int id;
  string name;
  double salary;

public:
  Employee(int id, string n, double s){
    this->id = id;
    this->name = n;
    this->salary = s;
  }

  void display(){
    cout << "Employee id" << id << endl;
    cout << "Employee name" << name << endl;
    cout << "Employee salary" << salary << endl;
  }
};

class Manager : public Employee{
private:
  double bonus;

public:
  Manager(int id, string name, double salary, double b) : Employee(id, name, salary){
    cout << "I am inside Manager Constructor" << endl;
  }

};

int main()
{

    cout << endl;
    Car A("Maruti 800", "LXI", 4, 4, "Manual"); // 1st base case properties are intialised then child class properties
    A.start_engine();
    A.startAC();
    A.stop_engine();
    cout << endl;

    MotorCycle M("BMW", "VXI", 2, "U", "Hard");
    M.start_engine();
    M.wheelie();
    M.stop_engine();
    cout << endl;

    // Constructor : 1st base class constructor is called & then derived class constructor is called.

    // Destructor : 1st derived class destructor is called & then base class destructor is called.

    // Employee E1(101, "Teja", 100000);
    // E1.display();

    // Manager M1(201, "Manager ", 200000, 10000);
    // M1.display(); // Manager class does not have display method, but it is inherited from Employee class.


    return 0;
}
