class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        auto com = [](const vector<int>& a, const vector<int>& b){
            return a[0] <  b[0];
        };
        sort(intervals.begin(), intervals.end(), com);

        vector<int> sortq(queries);
        sort(sortq.begin(), sortq.end());

        auto compq = [](const vector<int>& a, const vector<int>& b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]);
        };
        unordered_map<int, int> res;
        priority_queue<vector<int>, vector<vector<int>>, decltype(compq)> pq(compq);
        int index = 0;
        for(int i : sortq){
            while(index < intervals.size() && intervals[index][0] <= i){
                pq.push({intervals[index][1] - intervals[index][0] + 1, intervals[index][1]});
                index++;
            }
            while(!pq.empty() && i > pq.top()[1]){
                pq.pop();
            }
            res[i] = pq.empty() ? -1 : pq.top()[0];
        }
        vector<int> result;

        for(int i : queries){
            result.push_back(res[i]);
        }
        return result;
    }
 
};
