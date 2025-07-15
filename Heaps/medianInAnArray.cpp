class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    double median;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // CASE 1 : equal size case
        if(maxHeap.size() == minHeap.size()){
          if(num > median){ // compare the num with median //        (num > median) push right (minHeap)
            // insert at right
            minHeap.push(num);
            median = minHeap.top();
          }
          else{
            // insert at left
            maxHeap.push(num);
            median = maxHeap.top();
          }
        }
        // CASE 2 : not equal size
        else if(maxHeap.size() == minHeap.size() + 1){ 
          // CASE A :  maxHeap ka size bada hai minHeap se by 1
          if(num > median){
            // insert at right
            minHeap.push(num);
            median = (maxHeap.top() + minHeap.top()) / 2.0;
          }
          else{
            // insert at left
            // but maxHeap size is already big than minHeap
            // first offload element
            // insert it in minHeap
            // then insert in maxHeap
            int element = maxHeap.top(); maxHeap.pop();
            minHeap.push(element);
            maxHeap.push(num);
            median = (maxHeap.top() + minHeap.top()) / 2.0;
          }
        }
        else if(maxHeap.size() + 1 == minHeap.size()){ 
          // CASE B : minHeap ka size bada hai minHeap se by 1
          if(num > median){
            // insert at right
            // but minHeap size is already big than maxHeap
            // first offload element
            // insert it in maxHeap
            // then insert in minHeap
            int element = minHeap.top(); minHeap.pop();
            maxHeap.push(element);
            minHeap.push(num);
            median = (maxHeap.top() + minHeap.top()) / 2.0;
          }
          else{
            // insert at left
            maxHeap.push(num);
            median = (maxHeap.top() + minHeap.top()) / 2.0;
          }
        }
    }
    
    double findMedian() {
        return median;
    }
};
