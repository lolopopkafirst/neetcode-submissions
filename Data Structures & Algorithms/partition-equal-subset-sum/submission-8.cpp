class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(int i : nums){
            sum+=i;
        }
        if(sum % 2 != 0){
            return false;
        }
        vector<vector<int>> memo(nums.size() + 1, vector<int>((sum / 2 + 1), -1));
        return helper(nums, sum / 2, 0, 0, memo);
    }
    bool helper(vector<int>& nums, int target, int current, int index, vector<vector<int>>& memo){
        // cout << "current " <<  current << " ";
        // cout << "index " <<  index << "\n";
        if(current == target) return true;
        if(current > target || index >= nums.size()) return false;
        if(memo[index][current] != -1) return memo[index][current];
        bool take = helper(nums, target, current + nums[index], index + 1, memo); 
        bool skip = helper(nums, target, current, index + 1, memo);
        memo[index][current] = take || skip;
        return memo[index][current];
    }
};
