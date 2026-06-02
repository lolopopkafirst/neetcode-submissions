class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool res = false;
        helper(nums, nums[0], res, 0);
        return res;
    }
    bool helper(vector<int>& nums, int jump, bool& res, int index) {
        cout << index << " ";
        if(nums.size() - index - 1 <= jump){
            res = true;
            return true;
        } 
        for(int i = 1 ; i <= jump ; i++){
           if(helper(nums, nums[index + i], res, index + i)){
                return true;
           };
        }
        return false;
    }
};
