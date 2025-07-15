#include<iostream>
#include<vector>
using namespace std;

// TOP DOWN UPROACH : Recursive approach
int solveUsingMem(int n, vector<int>&dp){
  if(n == 0)
    return 0;
  
  if(n == 1)
    return 1;

  // step 3 : base case ke baad, check if ans already exists
  if(dp[n] != -1){
    return dp[n];
  }

  // step 2 : dp array me ans store karo and return karo 
  dp[n] = solveUsingMem(n-1, dp) + solveUsingMem(n-2, dp);
  return dp[n];
}

// BOTTOM UP UPROACH : Iterative approach
int solveUsingTabulation(int n){

  // step 1 : create a dp array
  vector<int>dp(n+1, -1);

  // step 2 : analyse base case and update dp array
  dp[0] = 0;

  if(n == 0){
    return 0;
  }

  dp[1] = 1;

  // step3: check parameter and reverse it and rum a loop
  for(int i=2; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }

  return dp[n];
}

// Using Bottom Up Approach with Space Optimization
int usingTabulationSpaceOptimization(int n){
  // base case
  if(n == 0) return 0;
  if(n == 1) return 1;
  int prev = 0;
  int curr = 1;

  for(int i=2; i<=n; i++){
    int ans = prev + curr;
    prev = curr;
    curr = ans;
  }
  return curr;
}

int fib(int n){
  // step 1 : create a dp array
  vector<int>dp(n+1, -1);

  return solveUsingMem(n, dp);
  // return solveUsingTabulation(n);
}

int main(){
  int n = 4;

  cout << "Top Down Approach ans : "<< fib(n) << endl;

  cout << "Bottom Up Approach ans : " << solveUsingTabulation(n) << endl;

  cout << "Bottom Up Approach with Space Optimization ans : " << usingTabulationSpaceOptimization(n) << endl;

  return 0;
}