#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class TrieNode{
public:
  char value;
  unordered_map<char, TrieNode*>children;
  bool isTerminal;

  TrieNode(char data){
    value = data;
    isTerminal = false;
  }
};

// Recursive Approach
void insertIntoTrie(TrieNode* root, string word){
  // base case
  if(word.length() == 0){
    root->isTerminal = true;
    return;
  }
  
  char ch = word[0];
  TrieNode* child;
  
  // present hai toh waha chale jao
  if(root->children.find(ch) != root->children.end()){
    // present
    child = root->children[ch];
  }
  else{
  // absent hai toh create karo
  child = new TrieNode(ch);
  // link
    root->children[ch] = child;
  }
  insertIntoTrie(child, word.substr(1));
}

// Recursive Approach
bool searchTrie(TrieNode* root, string word){
  // base case
  if(word.length() == 0){
    return root->isTerminal;
  }
  // if(word.length() == 0){
  //   if(root->isTerminal == true)
  //     return true;
  //   else
  //     return false;
  // }

  char ch = word[0];
  TrieNode* child;

  // 1 case mei solve karunga
  if(root->children.find(ch) != root->children.end()) {
    // present
    child = root->children[ch];
  }else {
    // absent
    return false;
  }
  // baaki recursion 
  bool recursionAns = searchTrie(child, word.substr(1));
  return recursionAns;
}

// Recursive Approach
void deleteWord(TrieNode* root, string word){
  // base case
    if(word.length() == 0){
      if(root->isTerminal){
        root->isTerminal = false;
        cout << "Word deleted successfully!" << endl;
      }
      else{
        cout << "Word not found!" << endl;
      }
    return;
  }

  char ch = word[0];
  TrieNode* child;

  // 1case mei solve karunga
  if(root->children.find(ch) != root->children.end()){
    // present
    child = root->children[ch];
  }
  else{
    // absent
    cout << "Word not found!" << endl;
    return;
  }
  // baaki recursion sambhal lega
  deleteWord(child, word.substr(1));
}

// Iterative Approach
void insertIntoTrieIterative(TrieNode* root, string word){
  TrieNode* curr = root;

  for(char ch: word){
    if(curr->children.find(ch) != curr->children.end()){
      // present
      curr = curr->children[ch];
    }
    else{
      // absent
      curr->children[ch] = new TrieNode(ch);
    }
  }
  curr->isTerminal = true;
}

void searchTrieIterative(TrieNode* root, string word){
  TrieNode curr = root;
  for(char ch : word){
    if(curr->children.find(ch) != curr->children.end()){
      // present
      curr = curr->children[ch];
    }else{
      // absent
      return false
    }
  }
}// ........

void storeString(TrieNode* root, vector<string>&ans, string output){
  // base case
  if(root->isTerminal){
    ans.push_back(output);
  }
  
  //1 case 
  for(auto i: root->children) {
    char ch = i.first;
    output.push_back(ch);
    TrieNode* child = i.second;
    storeString(child, ans, output);
    output.pop_back();
  }
}


void findWordsWithPrefix(TrieNode* root, string prefix, vector<string>&ans){
  // base case
  if(prefix.length() == 0){
    //prefix pura search ho chuka hai
    // and root abhi prefix string ke last character ko store krri hogi
      string temp = "";
     storeString(root, ans, temp);
     return;
  }

  char ch = prefix[0];
  TrieNode* child;
  // 1 case
  if(root->children.find(ch) != root->children.end()){
    // present
    child = root->children[ch];
  }
  else{
    // absent
    return;
  }
  findWordsWithPrefix(child, prefix.substr(1), ans);

}

int main() {

  TrieNode* root = new TrieNode('-');
  // string word = "cover";

  // insertIntoTrie(root, "cover");
  // insertIntoTrie(root, "care");
  // insertIntoTrie(root, "caretaker");
  // insertIntoTrie(root, "core");

  // searchTrie(root, "abd") ? cout << "Present inside Trie" << endl : cout << "Absent" << endl;
  
  // deleteWord(root, "abd");
  // cout << "Deleted successfully !" << endl;

  insertIntoTrie(root, "babar");
  insertIntoTrie(root, "baby");
  insertIntoTrie(root, "baba");
  insertIntoTrie(root, "bala");

  string prefix = "bab";

  vector<string>ans;
  findWordsWithPrefix(root, prefix, ans);

  for(int i=0; i<ans.size(); i++){
    string str = prefix + ans[i];
    ans[i] = str;
    cout << ans[i] << " " << endl;
  }

  

  return 0;
}