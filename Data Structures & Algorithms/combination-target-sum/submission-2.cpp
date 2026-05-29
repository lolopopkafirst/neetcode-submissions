class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res{};
        vector<int> acc{};
        helper(nums, target, 0, res, {}, 0);
        return res;
    }
    void helper(vector<int>& nums, int target, int index, vector<vector<int>>& res, vector<int> acc, int total) {
        
        if(total == target){
            res.push_back(acc);
            return;
        }
        for (int j = index; j < nums.size(); j++) {
            if(total + nums[j] > target){
                return;
            }
            acc.push_back(nums[j]);
            helper(nums, target, j, res, acc, total + nums[j]);
            acc.pop_back();
        }
 
        
   

        
        
    }
};
