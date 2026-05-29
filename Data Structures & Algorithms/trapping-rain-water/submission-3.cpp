class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        int maxL = 0, maxR = 0;
        while(l < r){
            if(height[l] <= height[r]){
                maxL = max(height[l], maxL);
                res += maxL - height[l];
                l++;
            }
            else if(height[l] > height[r]){
                maxR = max(height[r], maxR);
                res += maxR - height[r];
                r--;
            }
        }
       
        return res;
    }


   
};
