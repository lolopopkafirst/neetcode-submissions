class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      
        
        sort(intervals.begin(), intervals.end());
        cout << "[";
        for(auto& i : intervals){
            cout << "[" << i[0] << ", " << i[1] << "], ";
        }
        cout << "]";
        int res = 0;
        vector<int> curr = intervals[0];
        for(int r = 1 ; r < intervals.size() ; r++){
            if(curr[1] > intervals[r][0] || curr[1] == intervals[r][1]){
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
