#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

// Every Tree can be a Graph,
// But A Graph cannot be a Tree 

// Graph Implementation : 1 Adjacency Matrix // TC : O(v²), SC : O(v² ) 
//                        2 Adjacency List   // majorly used

class Graph{
public:
  //               u  ,       v
  // unordered_map<int, list<int>>adjList;
  //             u ,          {  v, wt }
  unordered_map<int, list<pair<int, int>>>adjList;

  void addEdge(int u, int v, int wt, bool direction){ // TC : O(1), SC : O(V + E)
    // direction = 0 -> undirected graph
    // direction = 1 -> directed graph
    if(direction == 0){
      // undirected graph
      adjList[u].push_back({v, wt});
      adjList[v].push_back({u, wt});
    }else{
      // directed graph
      adjList[u].push_back({v, wt});
    }
  }

  void printAdjList(int n){ // TC : O(V + E), SC : O(1)
    for(int i=0; i<n; i++){
      cout << i << ": ";
      cout << "{ ";
      list<pair<int, int>>temp = adjList[i];
      for(auto j: temp){
        // j is pair
        cout << "{" << j.first << "," << j.second << "}, ";
      }
      cout << " }" << endl;
    }
  }


  // Tracersal : BFS, DFS, Topological sort

  // BFS : level order traversal in Tree is BFS in Graph
  
  void BFSTraversal(int src){ // TC : O(V + E), SC : O(V)
    queue<int>q;
    unordered_map<int, bool>visited;

    // initial state
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
      int frontNode = q.front();
      cout << frontNode << ", ";
      q.pop();

      // neighbour
      for(auto neighbour: adjList[frontNode]){
        // neighbour -> pair
        // first -> node
        // second -> weight
        int node = neighbour.first;
        int weight = neighbour.second;
        if(!visited[node]){
          q.push(node);
          visited[node] = true;
        }
      }
    }
  }


  void dfshelper(int src, unordered_map<int, bool>& visited){
    visited[src] = true;
    cout << src << ", ";

    for(auto nbr : adjList[src]){
      // nbr -> pair
      // first -> node
      // second -> weight
      int node = nbr.first;
      if(!visited[node]){
        dfshelper(node, visited);
      }
    }
  }


  void DFSTraversal(int n){  // TC : O(V + E), SC : O(V)
    unordered_map<int, bool>visited;

    for(int src = 0; src<n; src++){ // IMP : Disconnected components ko travel karne ho tho saare node ko source maan ke chalo upto number of nodes
      if(!visited[src]){
        dfshelper(src, visited);
      }
    }
  }

  // Cycle Detection : 
  // 1) Directed :  BFS, DFS 
  // 2) Undirected :  BFS, DFS
  
  bool cycleDetectionUndirectedBFS(int src, unordered_map<int, bool>&visited){
    queue<int>q;
    unordered_map<int, int>parent;
  
    //inital state
    q.push(src);
    visited[src] = true;
    parent[src] = -1;
  
    // main logic
    while(!q.empty()){
      int frontNode = q.front();
      q.pop();
  
      for(auto nbrPair: adjList[frontNode]){
        int nbr = nbrPair.first;
        if(!visited[nbr]){
          q.push(nbr);
          visited[nbr] = true;
          parent[nbr] = frontNode;
        }
        // cycle detection case
        else if(nbr != parent[frontNode]){
          return true;
        }
      }
    }
    return false;
  }

};


int main() {
  Graph g;
  g.addEdge(0, 1, 3, 1);
  g.addEdge(1, 2, 4, 1);
  g.addEdge(2, 3, 1, 1);
  g.addEdge(3, 0, 16, 1);
  // g.addEdge(0, 3, 3, 1);
  // g.addEdge(0, 3, 3, 1);
  // g.addEdge(0, 2, 3, 1);
  // g.addEdge(2, 5, 3, 1);
  // g.addEdge(3, 5, 3, 1);
  // g.addEdge(5, 4, 3, 1);
  // g.addEdge(5, 6, 3, 1);
  // g.addEdge(4, 1, 3, 1);
  // g.addEdge(6, 1, 3, 1);
  int n = 4;

  g.printAdjList(n);
  // cout << endl;
  // cout << "BFS: " << endl;

  // g.BFSTraversal(0);
  // cout << endl;
  // cout << "DFS: " << endl;;
  // g.DFSTraversal(n);

  bool ans = false;
  unordered_map<int, bool>visited;

  for(int i=0; i<n; i++){
    if(!visited[i]){
        ans = g.cycleDetectionUndirectedBFS(i, visited);
      if(ans == true){
        break;
      }
    }
  }

  if(ans == true){
    cout << "Cycle Present " << endl;
  }else{
    cout << "Not Present" << endl;
  }

  return 0;
}

