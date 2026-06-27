class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 0 ; i < coins.size() ; ++i){
            if(dp.size() > coins[i]){
                dp[coins[i]] = 1;  
            }
        }
        for(int i = 1 ; i < amount + 1 ; i++){
            if(dp[i] == amount + 1){
                for(int coin : coins){
                    if(coin < i){
                        if(dp[i - coin] == amount + 1){
                            continue;
                        }
                        else{
                            dp[i] = min(dp[i], 1 + dp[i - coin]);
                        }
                    }
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];

    }
    
};
