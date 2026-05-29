class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        auto com = [](vector<int>& a, vector<int>& b){return ((a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1])) ;
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(com)> minHeap;
        for(vector<int>& point : points){
            minHeap.push(point);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        while(!minHeap.empty()){
            res.push_back(minHeap.top());
            minHeap.pop();
        }
        return res;

    }
};
