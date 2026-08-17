class Solution {
   public:
    int findTargetSumWays(vector<int>& num, int target) {
        int sum = 0;
        for (int i : num){
            sum += abs(i);
        }
        vector<vector<int>> memo(num.size() + 1, vector<int>(sum * 2 + 1, -1));
         return rek(target, num, 0, memo, sum); 
         }
    int rek(int target, vector<int>& num, int index, vector<vector<int>>& memo, int middle) {
        if (abs(target) > middle) {
        return 0;
         }
        int id = target + middle;
        
        if((index >= num.size() && target != 0)){
             return 0;
        }
        if ((index >= num.size() && target == 0)) {
            return 1;
        } 
       
        if(memo[index][id] != -1) {
            return memo[index][id];
        }
        
        
        int minus = rek(target + num[index], num, index + 1, memo, middle);
        int plus = rek(target - num[index], num, index + 1, memo, middle);
        memo[index][id] = minus + plus;
        return memo[index][id];
    }
};
