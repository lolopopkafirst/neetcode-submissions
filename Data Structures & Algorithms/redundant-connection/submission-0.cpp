class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        std::vector<std::vector<int>> childs(n + 1);
        for(auto& v : edges){
            std::vector<bool> visited(n + 1, false);
            if(dfs(childs, v[0], v[1], visited)) return v;
            childs[v[0]].push_back(v[1]);
            childs[v[1]].push_back(v[0]);
        }
        return {1};
        
    }
    bool dfs(std::vector<std::vector<int>>& childs, int u, int v, std::vector<bool>& visited){
        if(u == v) return true;
        visited[u] = true;
        for(int i : childs[u]){
            if(!visited[i]){
                if(dfs(childs, i, v, visited)){
                    return true;
                }
            }
        }
        return false;
    }
    
};
