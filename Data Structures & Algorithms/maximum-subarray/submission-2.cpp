class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = 0;
        int res = nums[0];
        for(int i : nums){
            m += i;
            res = max(res, m);
            if(m < 0){
                m = 0;
            }
            
 
        }
        return res;
    }
};
