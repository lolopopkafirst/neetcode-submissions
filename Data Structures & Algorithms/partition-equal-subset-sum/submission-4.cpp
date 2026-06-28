class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> fixed;
        for(int l = 0 ; l < nums.size() ; l++){
            fixed.clear();
            for(int i = l ; i < nums.size() ; i++){
                fixed.insert(i);
                if(helper(nums, fixed)){
                    return true;
                }
                for(int j = i + 1 ; j < nums.size() ; j++){
                    fixed.insert(j);
                    if(helper(nums, fixed)){
                        return true;
                    }
                    fixed.erase(j);
                }
            }
        }
            return false;
    }

    bool helper(vector<int>& nums, unordered_set<int>& fixed){
        int currsum = 0;
        for(int i : fixed){
            // cout << i << " ";
            currsum += nums[i];
        }
        // cout << "\n";
        int rest = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(fixed.find(i) == fixed.end()){
                // cout << i << " ";
                rest += nums[i];
            }
        }
        // cout << "\n";
        // cout << "curr " << currsum << " rest " << rest;
        // cout << "\n";
        if(rest == currsum) return true;
        return false;
    }
};
