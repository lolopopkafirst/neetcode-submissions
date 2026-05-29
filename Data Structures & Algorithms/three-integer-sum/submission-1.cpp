class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
          vector<vector<int>> result;

          for(int k = 1 ; k < nums.size() ; k++){
            int target = -1 * nums[k - 1];
            int right = nums.size() - 1;
            int left = k;
            while(left < right){
                if(nums[left] + nums[right] == target){
                    result.push_back(vector<int> {nums[k-1] , nums[left], nums[right]});
                }
                right--;
                if(left == right){
                    left++;
                    right = nums.size() - 1;
                }
            }
          }
        for(auto& v : result){
            sort(v.begin() , v.end());
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};
