class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        auto com = [](vector<int>& a, vector<int>& b){return sqrt(pow((a[0] - 0), 2) + pow((a[1] - 0), 2)) < sqrt(pow((b[0] - 0), 2) + pow((b[1] - 0), 2));
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
