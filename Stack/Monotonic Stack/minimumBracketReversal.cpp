#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int minimumBracketReversal(string &s){
    // edge case impossible to solve case: if string length is odd 
    int n = s.length();
    if(n % 2 != 0){
        return -1;
    }

    int open = 0;
    int close = 0;
    
    for(char ch : s){
        if(ch == '{'){
            open++;
        }else{ // ch == '}'
            if(open > 0){
                open--;
            }else{
                close++;
            }
        }
    }
    int result = ceil(open / 2) + ceil(close / 2);
    return result; 
}

int countRev(string s){
    int n = s.length();
    if(n % 2 != 0) return -1;
    stack<char>st;
    
    for(char ch: s){
        if(ch == '{'){
            st.push(ch);
        }else{ // ch == '}'
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }else{
                st.push(ch);
            }
        }
    }
    int open = 0, close = 0;
    while(!st.empty()){
        if(st.top() == '{') open++;
        else close++;
        st.pop();
    }
    return (open + 1) / 2 + (close + 1) / 2;
}

int main(){

    string s = "}{{}}{{{";
    int ans = minimumBracketReversal(s);
    cout << ans << endl;

    return 0;
}