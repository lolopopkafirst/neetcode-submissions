class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> um;
        int curr = -100;
        int count = 0;
        for(int num : nums){
            if(curr == num){ count++; }
            else{curr = num; count = 1;}{
            um[count].push_back(curr);
            }
        }
        for(int i = um.size(); i > 0; i--){
            if(um[i].size() >= k) return um[i];
        }
        return um[0];
    }
};
