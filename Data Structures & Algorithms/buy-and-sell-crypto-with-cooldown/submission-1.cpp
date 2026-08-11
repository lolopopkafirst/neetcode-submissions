class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        vector<vector<int>> profit(sz, vector<int>(2, -1));
        
         
        
        return rek(0, false, prices, profit);;
    
    }
    int rek(int day, bool bought, vector<int>& prices, vector<vector<int>>& profit){
        if(day >= prices.size()) return 0;
        if(profit[day][bought] != -1) return profit[day][bought];
        if(!bought){
            int buy = rek(day + 1, true, prices, profit) - prices[day];
            int notBuy = rek(day + 1, false, prices, profit);
            profit[day][0] = max(buy, notBuy);
        }
        else{
            int sell = rek(day + 2, false, prices, profit) + prices[day];
            int notSell = rek(day + 1, true, prices, profit);
            cout << profit[day][0];
            profit[day][1] = max(sell, notSell);
        }
        return profit[day][bought];
        
    }
};
