#include<iostream>
using namespace std;

int main(){
    

    // Rectangle
    // for(int i=0; i<6; i++){
    //     for(int j=0; j<6; j++){
    //         cout << "* ";
    //     }cout << endl;
    // }

    // Triangle
    // int row = 6;
    // for(int i=0; i<row; i++){ //printing rows
    //     for(int j=0; j<i+1; j++){ // columns
    //         cout << "* ";
    //     }cout << endl;
    // }

    // alphabets
    for(int i=0; i< 5; i++){
        char ch;
        for(int j=0; j<i+1; j++){
            char ch = j + 'A'; // 95 a->64
            cout << ch;
        }cout << endl;
    }



    return 0;
}