#include<iostream>
using namespace std;


int main(){

    string s1 = "Hello";
    string s2 = "World 123";
    string res = "";
    int i=0;
    for(i; i<s1.length() && i<s2.length(); i++){
        res +=  s1[i];
        res += s2[i];
    }
    while(i<s1.length()){
        res += s1[i];
        i++;
    }
    while(i<s2.length()){
        res += s2[i];
        i++;
    }
    
    cout << res << endl;
    return 0;
}
