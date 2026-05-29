class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        vector<vector<int>> array(nums.size() + 1);
        vector<int> res;
        for(int num : nums){
                um[num]++;
        }
        for(auto& [num, count] : um){
            array[count].push_back(num);
        }
        for(int i = nums.size() ; k != 0 ; i--){
            if(array[i].size() != 0){
                for(int l : array[i]){
                    res.push_back(l);
                    if(--k == 0) break;
                } 
            
            }
        }
        return res;
    }
};
