class MedianFinder {
private: 
    priority_queue<int> pqMax;
    priority_queue<int, vector<int>, greater<int>> pqMin;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(pqMax.empty() || num < pqMax.top()){
           pqMax.push(num);
        }
        else{
           pqMin.push(num);
        }

        while(pqMax.size() + 1 < pqMin.size() ){
            pqMax.push(pqMin.top());
            pqMin.pop();
        }
        while(pqMax.size() > pqMin.size() + 1){
            pqMin.push(pqMax.top());
            pqMax.pop();
        }
    }
    
    double findMedian() {
        if(pqMax.size() > pqMin.size()){
            return (double) pqMax.top();
        }
        else if(pqMax.size() < pqMin.size()){
            return (double) pqMin.top();
        }
        return (pqMin.top() + pqMax.top()) / 2.0;

    }
};
