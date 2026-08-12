class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(amount + 1, vector<int>(coins.size(), -1));
        return rek(amount, coins, 0, memo);
    }
    int rek(int curr, vector<int>& coins, int id, vector<vector<int>>& memo){
        if(curr == 0) return 1;
        if(curr < 0 || id >= coins.size()) return 0;
        if(memo[curr][id] != -1) return memo[curr][id];
        int take = rek(curr - coins[id], coins, id, memo);
        int notTake = rek(curr, coins, id + 1, memo);
        memo[curr][id] = take + notTake;
        return memo[curr][id];
    }
};
