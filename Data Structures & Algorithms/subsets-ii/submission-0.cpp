class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> acc;
        sort(nums.begin(), nums.end());
        helper(nums, acc, 0, res);
        return res;
    }
    void helper(vector<int>& nums, vector<int>& acc, int index,
    vector<vector<int>>& res){
        
        if(index >= nums.size()){
            res.push_back(acc);
            return;
        }
        
        acc.push_back(nums[index]);
        helper(nums, acc, index + 1, res);
        acc.pop_back();
        while(index + 1 < nums.size() && nums[index] == nums[index + 1]){
            index++;
        }
        helper(nums, acc, index + 1, res);
    }
    
   
};
