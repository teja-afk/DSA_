// #include<iostream>
// using namespace std;

// int slowExponentiation(int a, int b){
//   int ans = 1;
//   for(int i=0; i<b; i++){
//     ans *= a;
//   }
//   return ans;
// } // TC: O(b)

// int fastExponentiation(int a, int b){
//   int ans = 1;
//   while(b > 0){
//     if(b & 1){
//       //odd
//       ans *= a;
//     }
//     a = a * a;
//     b = b >> 1;
//   }
//   return ans;
// } // TC: O(log b)

// int main(){

//   // cout << slowExponentiation(5, 4) << endl;
//   cout << fastExponentiation(5, 4) << endl;

//   return 0;
// }



// #include<stdio.h>
// #include<conio.h> // header

// #include<iostream> // input output
// using namespace std; // alias

// int main(){
//   // int n;
//   // cin >> n; // extraction operator
//   // cout << "the no. is " << n << endl;
//   // printf("the no. is %d",n);
//   // cout << "this is to be display" << endl;  //insertion operator
  
//   char c;
//   cin >> c;
//   cout << "the charachter is " << c << endl;
  
//   return 0;
// }