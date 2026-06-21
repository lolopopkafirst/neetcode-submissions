class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int one = nums[0];
        int two = max(nums[0], nums[1]);
        for(int i = 2 ; i < nums.size() - 1 ; i++){
            int temp = two;
            two = max(two, one + nums[i]);
            one = temp;
        }
        int first = two;
        if(nums.size() <= 2) return first;
        one = nums[1];
        two = max(nums[2], nums[1]);
        for(int i = 3 ; i < nums.size() ; i++){

            int temp = two;
            two = max(two, one + nums[i]);
            one = temp;
        }
 
        return max(two, first);
    }
};
