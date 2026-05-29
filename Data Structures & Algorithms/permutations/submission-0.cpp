class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        set<vector<int>> res;
        
        int l = 0;
        int r = 1;
        vector<int> num = nums;
        res.insert(num);
        while(l < nums.size() && r < nums.size()){
            vector<vector<int>> acc;
            for(auto v : res){
                swap(v[l], v[r]);
                acc.push_back(v);
            }
            for(auto v : acc){
                res.insert(v);
            }
            r++;
            if(r == nums.size()){
                l++;
                r = l + 1;
            }
        }
        vector<vector<int>> result(res.begin(), res.end());
        return result;
    }
};
