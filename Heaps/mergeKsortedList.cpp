#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class ListNode{
  public:
    int val;
    ListNode* next;

    ListNode(int n){
      val = n;
      next = NULL;
    }
};

class compare{
  public:
    bool operator()(ListNode* a, ListNode* b){
      return a->val > b->val;
    }
};


ListNode* mergeKLists(vector<ListNode*>& lists) {
  priority_queue<ListNode*, vector<ListNode*>, compare>pq; // min heap

  for(auto head: lists){
    if(head) pq.push(head);
  }
  ListNode* ansHead = new ListNode(-1); // dummy node
  ListNode* it = ansHead;

  while(!pq.empty()) {
    ListNode* front = pq.top(); pq.pop();
    it->next = front;
    if(front->next){
      pq.push(front->next);
    }
    it = it->next;
  }
  return ansHead->next;
}

void printList(ListNode* head) {
  // if(head == NULL) return;

  while(head){
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}


int main() {

  ListNode* list1 = new ListNode(1);
  list1->next = new ListNode(4);
  list1->next->next = new ListNode(5); // 1 -> 4 -> 5

  ListNode* list2 = new ListNode(1);
  list2->next = new ListNode(3);
  list2->next->next = new ListNode(4); // 1 -> 3 -> 4
  
  ListNode* list3 = new ListNode(2);
  list3->next = new ListNode(6);       // 2 -> 6

  vector<ListNode*>lists = {list1, list2, list3};

  ListNode* ans = mergeKLists(lists);

  cout << "Merged Lists : ";
  printList(ans);

  return 0;
}