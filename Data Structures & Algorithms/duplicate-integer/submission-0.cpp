class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map <int, int> um;
        for(int i = 0; i < nums.size(); ++i) {
            if(um.count(nums[i]) && um[nums[i]] != i) return true;
            um[nums[i]] = i;
        }
        return false;
        
    }
};