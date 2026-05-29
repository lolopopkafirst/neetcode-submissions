class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        int minE = nums[0];
        while (l < r){
            mid = l + ((r - l) / 2);
            minE = min(minE, nums[mid]);
            cout << nums[mid];
            if(nums[l] > nums[mid]){
                r = mid;
            }
            else if(nums[r] < nums[mid]){
                l = mid + 1;
            }
            else if(nums[l] < nums[r]){
                return nums[l];
            }
        } 

        cout << minE;
        return nums[l];
    }
};
