class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = 0;
        int res = INT_MIN;
        for(int r = 0 ; r < nums.size() ; r++){
            for(int i = r ; i < nums.size(); i++){
                m+=nums[i];
                res = max(res, m);
            }
            m = 0;
        }
        return res;
    }
};
