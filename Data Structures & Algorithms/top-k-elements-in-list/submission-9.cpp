class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int n = nums.size();
        vector<vector<int>> res(n + 1);
        vector<int> result;
        for(int i : nums){
            um[i]++;
        }
        for(auto&[value, counter] : um){    
            res[counter].push_back(value);
        }
        for(int i = res.size() - 1 ; k > 0 ; i--){
            if(!res[i].empty()){
                for(int val : res[i]){
                    result.push_back(val);
                    k--;
                }
            }
        }
        return result;
    }
};
