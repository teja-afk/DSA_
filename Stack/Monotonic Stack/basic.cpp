#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> monotonicIncreasing(vector<int>&arr){
    vector<int>result;
    stack<int>st;
    int n = arr.size();

    for(int i=0; i<n; i++){
        while(!st.empty() &&  st.top() > arr[i]){
            st.pop();
        }
        st.push(arr[i]);
    }

    while(!st.empty()){
        result.insert(result.begin(), st.top());
        st.pop();
    }
    return result;
}

int main(){

    vector<int>arr = {1, 7, 9, 5};
    vector<int>result = monotonicIncreasing(arr);
    for(int num: result){
        cout << num << " "; 
    }cout << endl;

    return 0;
}