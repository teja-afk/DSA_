#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool isValid(string s){ // "babcc" failed testcase
    stack<char> st;
    for (char ch : s){
        if (ch == 'a' || ch == 'b'){
            st.push(ch);
        }
        else if ((ch == 'b' || ch == 'c') && st.empty()){
            return false;
        }
        else{ // ch == 'c'
            if (!st.empty() && st.top() == 'b'){
                st.pop();
                if (!st.empty() && st.top() == 'a'){
                    st.pop();
                }
            }
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}

bool isValid2(string s){
    vector<char>st;

    for(char ch: s){
        st.push_back(ch);
        if(st.size() >= 3 && st[st.size() - 3] == 'a' && 
            st[st.size() - 2] == 'b' && st[st.size() - 1] == 'c'){
                st.pop_back();
                st.pop_back();
                st.pop_back();
            }
    }
    return st.empty();
}

int main(){
    string s = "babcc";
    cout << isValid2(s) << endl;
    return 0;
}
