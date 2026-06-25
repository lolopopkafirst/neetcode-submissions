class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int minV = INT_MAX;
        for(int i = coins.size() - 1; i >= 0; i--){
            dfs(coins, amount, i, minV, 0);
        }
        return minV == INT_MAX ? -1 : minV;
    }
    void dfs(vector<int>& coins, int& amount, int id, int& minV, int steps){
        // cout << "step is " << steps << "\n"; 
        // cout << "amount is " << amount << "\n"; 
        // cout << "id is " << id << "\n";
        // cout << "\n";
        if(id < 0){
            // cout<<"return";
            return;
        } 
        if(amount == 0){

            minV = min(minV, steps);
            // cout << minV;
            return;
        }
        int curr = amount;
        if(amount - coins[id] >= 0){
            curr = amount - coins[id];
            dfs(coins, curr, id, minV, ++steps);
            curr+=coins[id];
            steps--;
        }
        dfs(coins, curr, --id, minV, steps);
    }
};
