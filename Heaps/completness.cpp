#include<iostream>
#include<queue>
using namespace std;

class Node {
  public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
      data = val;
      left = right = NULL;
  }
};


int countNodes(Node* root) {
  if(!root) return 0;
  int l = countNodes(root->left);
  int r = countNodes(root->right);
  return l + r + 1;
}

bool isCompleteTree2(Node* root, int i, int n) {
  if(!root) return true;
  if(i>n) return false;
  return isCompleteTree2(root->left, 2* i, n) && isCompleteTree2(root->right, 2* i + 1, n);
}
    
bool isCompleteTree(Node* root) {
  // level order traversal
  queue<Node*>q;
  q.push(root);
  bool nullFound = false;
  
  while(!q.empty()) {
    Node* front = q.front(); q.pop();
    
    if(front == NULL) {
      nullFound = true;
    }
    else{
      // front ek valid node hai
      if(nullFound == true){
        // not a CBT
        return false;
      }else{
        // may be continue
        q.push(front->left);
        q.push(front->right);
      }
    }
  }
  return true;
}
  
bool isMaxOrder(Node* root) {
  if(!root) return true;
  bool l = isMaxOrder(root->left);
  bool r = isMaxOrder(root->right);
  bool ans = false;

  if(!root->left && !root->right){ // leaf node
    ans = true;
  }else if(root->left && !root->right){ // only left node
    ans = root->data > root->left->data;
  }else{
    ans = root->data > root->left->data && root->data > root->right->data;
  }
  return ans;
}

bool isMaxProperty(Node* root) {
  // base case
  if(root == NULL) {
      return true;
  }
  
  if(root->left == NULL && root->right == NULL) {
      return true;
  }
  
  bool leftAns = isMaxProperty(root->left);
  bool rightAns = isMaxProperty(root->right);
  
  bool option1 = true;
  if(root->left && root->data < root->left->data) {
      option1 = false;
  }
  
  bool option2 = true;
  if(root->right && root->data < root->right->data) {
      option2 = false;
  }
  
  bool currAns = option1 && option2;
  
  if(currAns && leftAns && rightAns) {
      return true;
  }else{
      return false;
  }   
}
  
bool isHeap(Node* tree) {
  int n = countNodes(tree);
  int i = 1;
  bool completeness = isCompleteTree2(tree, i, n); 
  bool maxProperty = isMaxProperty(tree);
  return completeness && maxProperty;
}

int main() {

  Node* root = new Node(5);
  root->left = new Node(2);
  root->right = new Node(3);
  // root->left->left = new Node(40);
  // root->left->right = new Node(60);

  int i = 1;
  int n = 3;

  if(isCompleteTree2(root, i, n) && isMaxOrder(root)) cout << "True" << endl;
  else cout << "False" << endl;

  return 0;
}