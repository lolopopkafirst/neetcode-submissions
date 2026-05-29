class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> indices;

        for(int i = 0 ; i < heights.size() ; i++){
            int start = i;
            while(!indices.empty() && indices.top().second > heights[i]){
               pair<int, int> top = indices.top();
               indices.pop();
                maxArea = max(maxArea, top.second * (i - top.first));
               start = top.first;
            }
            indices.push({start, heights[i]});
        }
        while (!indices.empty()) {
            maxArea = max(maxArea, indices.top().second * ((int)heights.size() - indices.top().first));
            indices.pop();
        }
        return maxArea;
        
    }
};
