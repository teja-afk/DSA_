#include<iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  // for(int row = 0; row<n; row++){
  //   for(int col = row+1; col<n-row; col++){
  //     if(col==0 || col==n-row){
  //       cout << col+1;
  //     }
  //     else{
  //       if(col==0 || col==n-row){
  //         cout << col+1;
  //       }
  //       else{
  //         cout << " ";
  //       }
  //     }
  //   }
  //   cout << endl;
  // }

  for(int row=0; row<n; row++){
    for(int col=row+1; col<=n; col++){
      if(col==row+1 || col==n || row==0){
        cout << col;
      }
      else{
        cout <<" ";
      }
    }
    cout << endl;
  }

  return 0;
}