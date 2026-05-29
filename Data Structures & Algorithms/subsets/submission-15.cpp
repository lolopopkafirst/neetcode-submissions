class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        return helper(nums, res, sub, 0);
    }
    vector<vector<int>> helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& acc, int index) {
        if(index == nums.size()){
            res.push_back(acc);
        }
        else{
            acc.push_back(nums[index]);
            helper(nums, res, acc, index + 1);
            acc.pop_back();
            helper(nums, res, acc, index + 1);
        }
        return res;
    }

    
};
