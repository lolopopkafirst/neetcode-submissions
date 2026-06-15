class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_set<int> visited;
        unordered_map<int, vector<int>> um;
        for(auto& v : edges){
                um[v[0]].push_back(v[1]);
                um[v[1]].push_back(v[0]);
        }
        int counter = 0;
        for(int i = 0 ; i < n ; i++){
            if(visited.find(i) == visited.end()){
                    counter++;
                    dfs(visited, um, i, -1);
            } 
        }
        return counter;
        
    }
    void dfs(unordered_set<int>& visited, unordered_map<int, vector<int>>& um, int node, int parent){
        visited.insert(node);
        if(um.find(node) != um.end()){
            for(int i : um[node]){
                if(visited.find(i) == visited.end() && i != parent){
                    dfs(visited, um, i, node);
                } 
            }
        }
    }
};
