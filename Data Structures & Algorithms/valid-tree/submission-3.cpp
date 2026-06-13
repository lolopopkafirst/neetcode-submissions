class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) { 
        unordered_map<int, vector<int>> um;
        
        for(auto& v : edges){
            if(v[0] == v[1]) return false;
            um[v[0]].push_back(v[1]);
            um[v[1]].push_back(v[0]);
        }

        vector<int> state(n, 0);
        if(!dfs(um, state, 0, 0)){
            return false;           
        }
        
        for(int i : state){
            if(i == 0) return false;
        }
        
        return true;
    }

    bool dfs(unordered_map<int, vector<int>>& um , vector<int>& state, int curr, int parent){
        if(state[curr] == 1) return false;
        state[curr] = 1;
        for(int next : um[curr]){
            if(next == parent) continue;
            if(!dfs(um, state, next, curr)){
                return false;
            }
        }
        return true;
    }
};
