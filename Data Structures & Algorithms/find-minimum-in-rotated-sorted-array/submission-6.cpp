class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        while (l <= r){
            mid = l + ((r - l) / 2);
            if(nums[l] > nums[mid]){
                r = mid;
            }
            else if(nums[r] < nums[mid]){
                l = mid + 1;
            }
            else r--;
        } 
        return nums[l];
    }
};
