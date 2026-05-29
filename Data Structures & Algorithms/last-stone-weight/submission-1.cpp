class Solution {
private:
    priority_queue<int> minHeap;
public:
    int lastStoneWeight(vector<int>& stones) {
        for(int stone : stones){
            minHeap.push(stone);
        }
        while(minHeap.size() > 1){
            int x = minHeap.top();
            minHeap.pop();
            int y = minHeap.top();
            minHeap.pop();
            if(x == y) continue;
            else {
                minHeap.push(y > x ? y - x : x - y);
                continue;
            }
        }
        return minHeap.size() != 0 ? minHeap.top() : 0;
    }
};
