#include<iostream>
#include<queue>
using namespace std;

void print(int a){
    cout << a <<" ";
}

// first n fibonacci numbers
void fun(int n){
    queue<int>q;
    q.push(0);
    q.push(1);
    for(int i=0; i<n; i++){
        int a = q.front(); q.pop();
        int b = q.front(); q.pop();
        q.push(b);
        q.push(a+b);
        print(a);
    }
}

int main(){

    fun(50);

    return 0;
}
