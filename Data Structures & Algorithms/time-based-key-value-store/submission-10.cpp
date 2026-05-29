class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> db;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        db[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        const vector<pair<string, int>> &curr = db[key];
        if(curr.empty()) return "";
        int l = 0;
        int r = curr.size() - 1;
        int mid = 0;
        while(l <= r){
            mid = l + ((r - l) / 2);
            int ts = curr[mid].second;
            if(ts == timestamp) return curr[mid].first;
            else if(timestamp < ts){
                r = mid - 1;
            }
            else if (timestamp > ts){
                l = mid + 1;
            }

        } 
        if(r < 0){
            return "";
        }
        return curr[r].first;
    }

   
};
 
