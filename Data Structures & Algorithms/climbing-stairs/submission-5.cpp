class Solution {
public:
    int climbStairs(int n) {
        vector<int> DP(n+2, 0);
        DP[n] = 1;
        DP[n + 1] = 1;
        for(int i = n - 1 ; i > 0 ; i--){
            DP[i] = DP[i + 1] + DP[i + 2];
        }
        return DP[1];
    }

};