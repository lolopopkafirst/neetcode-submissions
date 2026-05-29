class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int result = 0;
        while(l < r){
            if(heights[l] > heights[r]) {
                if(result < heights[r] * (r - l)) result = heights[r] * (r - l);
            
                    r--;
                
            } else{
                if(result < heights[l] * (r - l)) result = heights[l] * (r - l);
          
                    l++;
                
            }
        }
        return result;
    }
};
