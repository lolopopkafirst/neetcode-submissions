class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res;
        bool found = false;
        int m = INT_MAX;
        for(int i : queries){
            m = INT_MAX;
            found = false;
            for(auto& v : intervals){
                if(v[0] <= i && i <= v[1]){
                    found = true;
                    m = min(m, v[1] - v[0] + 1);
                }
            }
            if(found){
                res.push_back(m);
            } 
            else res.push_back(-1);
        }
        return res;
    }
};
