class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set <int> um;
        for(int i : nums) {
            if(um.count(i)) return true;
            um.insert(i);
        }
        return false;
        
    }
};