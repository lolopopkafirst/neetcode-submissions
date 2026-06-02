class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int longest = 0;
        int curr = 0;
        for(int i = 0 ; i < nums.size() - 1 ; i++){
         
            longest = max(longest, nums[i]);
            if(curr == 0){
                step++;
                curr = longest;
            }
            longest--;
            curr--;
        }
        return step;
    }
};
