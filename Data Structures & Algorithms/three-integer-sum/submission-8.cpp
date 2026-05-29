class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
          sort(nums.begin(), nums.end());  
          vector<vector<int>> result;

          for(int k = 1 ; k < nums.size() ; k++){
            if(k != 1 && nums[k - 2] == nums [k - 1]) continue;

            int left = k;
            int right = nums.size() - 1;
            while(left < right){
        
                int sum = nums[k - 1] + nums[left] + nums[right];
                if(sum == 0){
                
                    result.push_back(vector <int> {nums[k - 1], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
                if(sum < 0){
                    left++;
                } else if (sum > 0) right--;
            }
          }
        return result;
    }
};
