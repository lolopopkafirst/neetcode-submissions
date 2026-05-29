class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool inserted = false;
        for(auto& v : intervals){
            if(v[0] > newInterval[1]){
                if(!inserted){
                    res.push_back(newInterval);
                    inserted = true;
                }
                res.push_back(v);
            }
            else if(v[1] < newInterval[0]){
                res.push_back(v);
            }
            else{
                vector<int> merged = {min(v[0], newInterval[0]), max(v[1], newInterval[1])};
                newInterval = merged;
            }
        }
        if(!inserted){
            res.push_back(newInterval);
            inserted = true;
        }
        return res;
    }
};
