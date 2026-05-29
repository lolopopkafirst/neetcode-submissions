class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int m = INT_MIN;
        vector<int> res;
        for(int r = 0; r < nums.size() ; r++){
            if(nums[r] > m) m = nums[r];
            if(r - l + 1 == k){
                res.push_back(m);
                if(nums[l] == m){
                    m = INT_MIN;
                    for(int i = l + 1 ; i < l + k; i++){
                        m = max(m, nums[i]);
                    }
                }
                l++;
            }
        }
        return res;
    }
};
