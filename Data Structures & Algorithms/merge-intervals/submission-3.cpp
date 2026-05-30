class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto com = [](vector<int>& a, vector<int>&b){
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), com);
        vector<int> curr = intervals[0];
        vector<vector<int>> res;
        for(int r = 1 ; r < intervals.size() ; r++){
            if(curr[1] < intervals[r][0]){
                res.push_back(curr);
                curr = intervals[r];
                continue;
            }
            else{
                curr = {min(curr[0], intervals[r][0]), max(curr[1], intervals[r][1])};
            }
        }
        res.push_back(curr);
        return res;
    }
};
