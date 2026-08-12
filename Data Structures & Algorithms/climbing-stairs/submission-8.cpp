class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, 0);
        return rek(n, memo);
    }
    int rek(int curr, vector<int>& memo){
        if(curr == 0){
            return 1;
        }
        if(curr < 0) return 0;
        if(memo[curr] != 0) return memo[curr];
        int goOne = rek(curr - 1, memo);
        int goTwo = rek(curr - 2, memo);
        memo[curr] = goOne + goTwo;
        return  memo[curr];
    }
};
