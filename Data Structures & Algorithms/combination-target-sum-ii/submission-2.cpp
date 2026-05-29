class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> acc;
        combinationSum2Helper(candidates, target, acc , res, 0);
        return res;
    }
    void combinationSum2Helper(vector<int>& candidates, int target,vector<int>& acc ,vector<vector<int>>& res,int index) {
        if(target == 0) {
            res.push_back(acc);
            return;
        }
        else if(target < 0 || index >= candidates.size()) return;
        for(int i = index ; i < candidates.size(); i++){
            if((target - candidates[i]) < 0) return;
            acc.push_back(candidates[i]);
            combinationSum2Helper(candidates, target - candidates[i], acc, res, i+1);
            acc.pop_back();
            while((i < candidates.size() - 1) && candidates[i + 1] == candidates[i]){
                i += 1;
            }
        }
        
    }
};
