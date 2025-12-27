#include <iostream>
using namespace std;

int main() {

  int a = 10, b=0;
  try{
    if(b == 0){
      throw " division by 0 error\n";
    }
    int res = a/b;
    cout << res << endl;

  }catch(const char* e){
    cout << "Exception Caught : " << e << endl;
  }
  
  return 0;
}
