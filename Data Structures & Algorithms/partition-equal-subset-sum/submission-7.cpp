class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums){
            sum+=i;
        }
        if(sum % 2 != 0){
            return false;
        }
        return helper(nums, sum / 2, 0, 0);
    }
    bool helper(vector<int>& nums, int target, int current, int index){
        // cout << "current " <<  current << " ";
        // cout << "index " <<  index << "\n";

        if(current == target) return true;
        if(current > target || index >= nums.size()) return false;
        return helper(nums, target, current + nums[index], index + 1) || 
        helper(nums, target, current, index + 1);
    }
};
