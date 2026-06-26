class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m = nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            int curr = nums[i];
            m = max(m , curr);
            for(int j = i + 1 ; j < nums.size() ; j++){
                curr *= nums[j];
                m = max(m , curr);
            }
            
        }
        return m;
    }
};
