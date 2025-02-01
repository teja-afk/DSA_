#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// TC: O(n^2) SC: O(2n)
int findCelebrity(vector<vector<int>>&mat){
    int knowsMe[] = {};
    int Iknows[] = {};
    int n = mat.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 1){
                knowsMe[j]++;
                Iknows[i]++;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(knowsMe[i] == n-1 && Iknows[i] == 0){
            return i;
        }
        return -1;
    }
}


// TC: O(n) SC: O(1)
int findCelebrity2(vector<vector<int>>&mat){
    int n = mat.size();
    int top = 0, down = n-1;
    while(top<down){
        if(mat[top][down] == 1){
            top++;
        }else {
            down--;
        }
    }
    // At this point, top == down
    int candidate = top;
    // confirm if its row contain all 0.
    // & its col contain all 1 except diagonal
    for(int i=0; i<n; i++){
        // if its diagonal it will contain 0 we will skip it.
        // since it can't knows himself
        if(i == candidate) continue;
        // row check
        // Here, top == down
        if((mat[candidate][i] == 1) || mat[i][candidate] == 0)
            return -1; //not a celebrity
    }
    return top;
}

// better understand
int celebrity(vector<vector<int>>& mat) {
        // push all possible elements onto stack
        stack<int>st;
        int n = mat.size();
        for(int i=0; i<n; i++){
            st.push(i);
        }
        
        // eliminate others that might not be possible,
        // if they know someone
        // there is only one possible celebrity
        while(st.size() != 1){
            // comparing top two elements
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            // either one is celebrity or not celebrity
            // eliminate not celebrity ones
            if(mat[a][b]){
                // a knows b then, a is not celebrity
                st.push(b); // b might be
            }else{ 
                // b knows a then, b is not celebrity
                st.push(a); // b might be
            }
        }
        // single element on stack
        // check is single element actually a celeb or not
        // row check
        int mightCeleb = st.top(); st.pop();
        for(int i=0; i<n; i++){
            if(mat[mightCeleb][i] != 0){
                return -1;
            }
        }
        // column & ignore diagonal check
        for(int i=0; i<n; i++){
            if(mat[i][mightCeleb] != 1 && i != mightCeleb){
                return -1;
            }
        }
        return mightCeleb;
    }

int main(){
    vector<vector<int>>mat;
    mat = {{1}, {0}};
    int ans = findCelebrity2(mat);
    cout << ans << endl;

    return 0;
}