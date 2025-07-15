#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

// 1 /*Median of Stream of Running Integers using STL*/
void printMedians(double arr[], int n){
	priority_queue<double> s;                                  // max Heap
	priority_queue<double, vector<double>, greater<double>> g; // min Heap
	double med = arr[0];
	s.push(arr[0]);
	cout << med << endl;
	for (int i=1; i < n; i++){
		double x = arr[i];
		if (s.size() > g.size()){
			if (x < med){
				g.push(s.top());
				s.pop();
				s.push(x);
			}
			else
				g.push(x);

			med = (s.top() + g.top())/2.0;
		}
		else if (s.size()==g.size()){
			if (x < med){
				s.push(x);
				med = (double)s.top();
			}
			else{
				g.push(x);
				med = (double)g.top();
			}
		}
		else{
			if (x > med){
				s.push(g.top());
				g.pop();
				g.push(x);
			}
			else
				s.push(x);

			med = (s.top() + g.top())/2.0;
		}

		cout << med << endl;
	}
}

// 2 /*k closest points to the origin using a priority queue*/
vector<pair<int, int>> kClosestPoints(vector<pair<int, int>> points, int n, int k){
  vector<pair<int, int>> ans;                                                                    // max Heap 
  priority_queue<int, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;  // min Heap

  for (int i = 0; i < n; i++){
    int distance = points[i].first * points[i].first + points[i].second * points[i].second;
    p.push({distance, {points[i].first, points[i].second}});
  }
  while (k--){
    auto x = p.top();
    ans.push_back({x.second.first, x.second.second});
    p.pop();
  }
  return ans;
}

// 3
vector<int> topKFrequent(vector<int>& nums, int k) {
  unordered_map<int,int>m; // { number : freq }
  
  for(int i=0; i<nums.size(); i++){
    m[nums[i]]++;
  }
  
  unordered_map<int,int> ::iterator it=m.begin();
  priority_queue<pair<int,int>>pq; // { freq, number }
  
  for(it;it!=m.end();it++){
    pq.push(make_pair(it->second, it->first));
  }
  
  vector<int>ans;
  int a=0;
  
  while(a<k){
    ans.push_back(pq.top().second);
    pq.pop();
    a++;
  }
  return ans;
  }

// 4
void kthSmallest(vector<int>& v, int N, int K){
	priority_queue<int> heap1;                     // MAX HEAP
	for (int i = 0; i < N; ++i) {
		heap1.push(v[i]);
		if (heap1.size() > K) {
			heap1.pop();
		}
	}
	cout << heap1.top() << endl;
}

// 5
vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
	if (intervals.empty()) {
		return vector<vector<int>>();
	}

	sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0];
	});

	stack<vector<int>> mergedStack;
	mergedStack.push(intervals[0]);

	for (int i = 1; i < intervals.size(); i++) {
		vector<int> current = intervals[i];
		vector<int>& top = mergedStack.top();
		if (current[0] <= top[1]) {
			top[1] = max(top[1], current[1]);
		} else {
			mergedStack.push(current);
		}
	}
	
  vector<vector<int>> mergedIntervals;

	while (!mergedStack.empty()) {
		mergedIntervals.insert(mergedIntervals.begin(), mergedStack.top());
		mergedStack.pop();
	}

	return mergedIntervals;
}

int main() {

  // 1
  // double arr[] = {5.0, 7.0, 9.0, 1.0, 3.0, 10.0, 8.0, 4.0};
  // int n = 8;
  // cout << "Array : ";
  // for(auto it: arr){
  //   cout << it << " ";
  // }cout << endl;
  // printMedians(arr, n);

  // 2
  // vector<pair<int, int>>points = {{-1, -1}, {1, 2}, {2, 2}, {3, 2}, {0, 1}};
  // int n = 5, k = 3;
  // vector<pair<int, int>> ans = kClosestPoints(points, n, k);
  // for(auto it: ans) {
  //   cout << "{ "<< it.first << ", "<< it.second << " }" << ", ";
  // }
  // cout << endl;

  // 3
  // vector<int>nums = {1, 2, 3, 4, 4, 3, 2, 1, 6, 7, 8, 9, 6, 4 ,3, 3}; // { 3 : 4}, { 4 : 3 }, { 6 : 2 }
  // int k = 3;
  // vector<int> ans = topKFrequent(nums, k);
  // for(auto it: ans) {
  //   cout << it << " ";
  // }
  // cout << endl;

  // 4
  // vector<int>v = {1, 2, 4, 3, 5, 6};
  // int N = 4;
  // int K = 3;
  // kthSmallest(v, N, K);

  // 5
  vector<vector<int>>intervals = {{1,3}, {2,4}, {6,8}, {7,9}};
  vector<vector<int>>ans = overlappedInterval(intervals); 
  cout << "Printing overlaped interval : ";
  for(int i=0; i<ans.size(); i++) {
    for(int j=0; j<ans[i].size(); j++) {
      cout << "{ "<< ans[i][j] << " }"<< " ";
    }
  }cout << endl;
    
  return 0;
}