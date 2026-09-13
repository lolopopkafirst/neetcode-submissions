class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int res = 0;
        vector<int> numsNew(nums.size() + 2, 1);
        for(int i = 0 ; i < nums.size(); i++){
            numsNew[i + 1] = nums[i];
        }
        vector<vector<int>> dp(numsNew.size(), vector<int>(numsNew.size(), -1));
        return rek(numsNew, 1, numsNew.size() - 2, dp);
   
    }
    int rek(vector<int>& nums, int l, int r, vector<vector<int>>& dp){
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        for(int i = l ; i <= r ; i++){
            int curr = nums[l - 1] * nums[i] * nums[r + 1];
            int left = rek(nums, l, i - 1,  dp);
            int right = rek(nums, i + 1, r,  dp);
            dp[l][r] = max(dp[l][r], (curr + left + right));
        }
        return dp[l][r];
    }
    void print(vector<int>& nums){
        cout << "{";
        for(int i : nums){
            cout << i << " ";
        }
        cout << "}\n";
    }
};
