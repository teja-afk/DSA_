#include<iostream>
#include<queue>
#include<stack>
using namespace std;
// Queue follows FIFO ordering 


// Using Recursion
void reverseQueueRC(queue<int>&q){
    // base case
    if(q.empty()){
        return;
    }
    int element = q.front();
    q.pop();

    reverseQueueRC(q);
    q.push(element);
}

void reverseInKGroups(queue<int>&q, int k, int count){
    stack<int>st;
    // can perform reverse if queue size is more than k
    if(count >= k){ // count stores current size of queue
        // queue se element pop kiya aur stack mei dala
        for(int i=0; i<k; i++){
            int element = q.front();
            st.push(element);
            q.pop();
        }
        // stack mei 'k' elements padhe hai
        // inko reverse karne hai
        for(int i=0; i<k; i++){
            int element = st.top();
            q.push(element);
            st.pop();
        }
        reverseInKGroups(q, k, count-k);

    }else{
        // can't perform reverse if queue size is less than k
        // reverse nhi ho sakthe tho aise he push karo
        for(int i=0; i<count; i++){
            int element = q.front();
            q.pop();
            q.push(element);
        }
    }
}

// Using Stack Iteratively
void reverseQueue(queue<int>&q){
    stack<int>st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}

void print(queue<int>q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}

int main(){

    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    q.push(110);

    int k = 3; // 3 ke group me reverse karna hai
    int count = q.size(); 
    // count tracks no. of elements in queue
    reverseInKGroups(q, k, count);
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    // queue<int>q;         
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // // cout << q.empty() << endl;
    // cout << "Before Queue : " << endl;
    // print(q);

    // reverseQueueRC(q);
    // cout << endl << "Reverse Queue : " << endl;
    // print(q);

    // reverseQueue(q);
    // cout << endl << "Reverse Queue : " << endl;
    // print(q);
    


    // // singly ended queue
    // deque<int>dq;
    // // insert
    // dq.push_front(10);
    // // 10
    // dq.push_front(30);
    // // 10 30
    // dq.push_front(50);
    // // 10 30 50
    // dq.push_back(70);
    // // 70 10 30 50
    // dq.push_back(100);
    // // 100 70 10 30 50
    // cout << dq.size() << endl;
    // cout << dq.empty() << endl;
    // cout << dq.front() << endl;
    // cout << dq.back() << endl;
    
    // // delete
    // dq.pop_front();
    // cout << dq.front() << endl;
    // dq.pop_back();
    // cout << dq.back() << endl;

    // // printing
    // while(!dq.empty()){
    //     cout << dq.back() <<" ";
    //     dq.pop_back();
    // }

    // Singly ended queue
    // queue<int>q;    // create
    // q.push(10);     // insert
    // q.push(20);     // insert
    // q.push(30);     // insert
    // q.push(40);     // insert

    // // front
    // cout << q.front() << endl;
    // // delete
    // q.pop();
    // cout << q.front() << endl;
    // // size
    // cout << q.size() << endl;
    // // rear element
    // cout << q.back() << endl;
    // // empty 
    // cout << q.empty() << endl;

    // printing
    // while(!q.empty()){
    //     cout << q.front() << " ";
    //     q.pop();
    // }
    
    return 0;
}
