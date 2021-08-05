class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    bool isEven = true;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(isEven){
            minq.push(num);
            maxq.push(minq.top());
            minq.pop();
        }
        else{
            maxq.push(num);
            minq.push(maxq.top());
            maxq.pop();
        }
        isEven = !isEven;
    }
    
    double findMedian() {
        if(isEven)
            return ((double)maxq.top()+minq.top())/2.0;
        else
            return maxq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */