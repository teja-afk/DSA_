#include<iostream>
#include<map>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {

  // unordered_map<int, string>uMap;
  // map<int, string>oMap;

  // uMap.insert({3, "baleno"});
  // uMap.insert({2, "fortuner"});
  // uMap.insert({1, "maruti"});
  
  // oMap.insert({3, "baleno"});
  // oMap.insert({2, "fortuner"});
  // oMap.insert({1, "maruti"});

  // cout << "Printing unordered map : " << endl;
  // for(auto it: uMap){
  //   cout << it.first << " -> " << it.second << endl;
  // }
  // cout << endl;
  // cout << "Printing ordered map : " << endl;
  // for(auto it: oMap){
  //   cout << it.first << " -> "  << it.second << endl;
  // }
  // cout << endl;

  // if(uMap.find(1) != uMap.end())
  //   cout << "Found!" << endl;
  // else
  //   cout << "Not Found!" << endl;
  
  string s = "barfoothefoobarman";
  vector<string>word = {"foo", "bar"};
  int totalWords = word.size();
  int totalTimes = word[0].size();
  int totalLength = totalWords * totalTimes;
  map<string, int>m; // { string, count }
  
  string concatenatedString(totalLength);
  cout << concatenatedString << endl;

  return 0;
}