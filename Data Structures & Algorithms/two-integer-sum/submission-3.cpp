class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int first = 0;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[first] + nums[i] == target){
                vector<int> res = {first, i};
                return res;
            } else if(i == nums.size() - 1){
                std::cout << i;
                ++first;
                i = first;
            }
        }
        
    }
};
