class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int,int>> memo(n + 1);
        memo[0][0] = 1;
        for(int i = 0 ; i < n ; i++){
            for(auto& p : memo[i]){
                memo[i+1][p.first + nums[i]] += p.second;
                memo[i+1][p.first - nums[i]] += p.second;
            }
        }
        return memo[n][target];
    }
};
