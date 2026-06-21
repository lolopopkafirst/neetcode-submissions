class Solution {
public:
    int climbStairs(int n) {
        int i = 1, ii = 1;
        for(int k = 0 ; k < n - 1 ; k++){
            int res = i;
            i = ii + i;
            ii = res;
        }
        return i;
    }
    
};