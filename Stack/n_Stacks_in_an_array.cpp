#include<iostream>
using namespace std;

class NStack{
public:
    int *arr;
    int *top;
    int *next;
    int s, n;

    int freespot;

    NStack(int N, int S){
        s = S;
        n = N;
        
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // initialise top
        for(int i=0; i<n; i++){
            top[i] = -1;
        }

        // initialise next
        for(int i=0; i<s; i++){
            next[i] = i+1;
        }

        next[s-1] = -1;

        freespot = 0;
    }

    bool push(int x, int m){
        // check overflow condition
        if(freespot == -1){
            return false;
        }

        // find index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // insert in an array
        arr[index] = x;

        // update next using purana top
        next[index] = top[m - 1];

        // update top
        top[m - 1] = index;

        return true;
    }

    int pop(int m){
        // check underflow condition
        if(top[m - 1] == -1){
            return -1;
        }

        int index = top[m - 1];
        
        top[m - 1] = next[index];
        
        next[index] = freespot;
        
        freespot = index;

        return arr[index];
    }
};

int main(){

    NStack nstack(3, 6);
    cout << nstack.push(10, 1) << endl;
    cout << nstack.push(20, 1) << endl;
    cout << nstack.push(30, 2) << endl;
    cout << nstack.pop(1) << endl;
    cout << nstack.pop(2) << endl;


    return 0;
}