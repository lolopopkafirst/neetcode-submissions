class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int result = 0;
        while(l < r){
            result = max(result, min(heights[r], heights[l]) * (r - l)); 
            if(heights[l] > heights[r]) {
                r--;}
            else{
                l++; 
                }
        }
        return result;
    }
};
