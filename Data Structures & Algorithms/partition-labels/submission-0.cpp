class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> um;
        unordered_set<char> pq;
        vector<int> res;
        int curr = 0;
        for(auto& c : s){
            um[c]++;
        }
        for(auto& c : s){
            curr++;
            if(um[c] != 0) pq.insert(c);
            um[c]--;
            cout << c << " " <<  um[c] << "; ";
            if(um[c] == 0){
                pq.erase(c);
            } 
            if(pq.empty()){
                res.push_back(curr);
                curr = 0;
            }
            for(char k : pq) cout << k << " ";
            cout << "\n";
        }
        return res;
    }
};
