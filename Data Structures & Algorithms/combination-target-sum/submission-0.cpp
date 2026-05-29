class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res{};
        vector<int> acc{};
        helper(nums, target, 0, res, acc);
        return res;
    }
    void helper(vector<int>& nums, int target, int index, vector<vector<int>>& res, vector<int>& acc) {
        if(index >= nums.size()){
            return;
        }
        if(target == 0){
            res.push_back(acc);
            return;
        }
        else if (target < 0){
            return;
        }
        acc.push_back(nums[index]);
        helper(nums, target - nums[index], index, res, acc);
        acc.pop_back();
        helper(nums, target, index + 1, res, acc);
        
        
    }
};
