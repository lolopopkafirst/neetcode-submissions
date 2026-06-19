class Solution {
public:
    int climbStairs(int n) {
       vector<int> arr(n + 2, 0);
       arr[0] = 1;  
       for(int i = 0; i < n ; ++i){
            arr[i + 1] += arr[i];
            arr[i + 2] += arr[i];
       }
       return arr[n];
    }
};