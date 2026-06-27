class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dpmin(nums.size(), 0);
       vector<int> dpmax(nums.size(), 0);
       dpmax[nums.size() - 1] = nums[nums.size() - 1]; 
       dpmin[nums.size() - 1] = nums[nums.size() - 1]; 

       for(int i = nums.size() - 2 ; i >= 0 ; --i){
            dpmax[i] = max({dpmax[i + 1] * nums[i], nums[i], dpmin[i + 1] * nums[i]});
            dpmin[i] = min({dpmax[i + 1] * nums[i], nums[i], dpmin[i + 1] * nums[i]});
       }
       return *max_element(dpmax.begin(), dpmax.end());
    }
};
