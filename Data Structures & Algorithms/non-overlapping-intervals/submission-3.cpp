class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res = 0;
        vector<int> curr = intervals[0];
        for(int r = 1 ; r < intervals.size() ; r++){
            if(curr[1] > intervals[r][0]){
                res++;   
                curr = curr[1] > intervals[r][1] ? intervals[r] : curr;
            }
            else{
                curr = intervals[r];
            }
        }
        return res;
    }
};
