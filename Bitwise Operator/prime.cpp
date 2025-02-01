#include<iostream>
using namespace std;

bool isPrime(int n){
  for(int i=2; i<=(n-1); i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}



int main(){

  // int n;
  // cout << "Enter a no. to check if prime or not : ";
  // cin >> n;

  // bool finalAns = isPrime(n);
  // if(finalAns){
  //   cout << "Prime";
  // }else{
  //   cout << "Not Prime";
  // }

  return 0;
}