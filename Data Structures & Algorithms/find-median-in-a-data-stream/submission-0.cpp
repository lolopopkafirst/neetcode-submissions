class MedianFinder {
private: 
    priority_queue<int> pq;
    int size;
public:
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        pq.push(num);
        size++;
    }
    
    double findMedian() {
        priority_queue<int> pqCopy(pq);

        if((size % 2) == 1){
            for(int i = 0 ; i < size / 2 ; i++){
                pqCopy.pop();
            }
            return pqCopy.top();
        }
        else{
            for(int i = 0 ; i < (size / 2) - 1; i++){
                pqCopy.pop();
            }
            int x1 = pqCopy.top();
            pqCopy.pop();
            int x2 = pqCopy.top();
            pqCopy.pop();
            return (x1 + x2) / 2.0;      
            }
    }
};
