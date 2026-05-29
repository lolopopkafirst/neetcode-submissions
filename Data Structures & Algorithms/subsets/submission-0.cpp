class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        for(int i : nums){
            int size = res.size();
            for(int k = 0 ; k < size ; k++){
                vector<int> subset = res[k];
                subset.push_back(i);
                res.push_back(subset);
            }
            
        }
        return res;
    }
    
};
