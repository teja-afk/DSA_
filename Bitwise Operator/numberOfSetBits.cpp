#include<iostream>
using namespace std;
int main(){

  int n;
  cin >> n;
  int setbitCount = 0;

  while(n != 0){
    int lastbit=(n&1);
    if(lastbit==1){
      setbitCount++;
    }
    n = n>>1;
  }
  cout << "SetBits : " << setbitCount;

  return 0;
}