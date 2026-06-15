class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> um(n);
        for(auto& v : edges){
                um[v[0]].push_back(v[1]);
                um[v[1]].push_back(v[0]);
        }
        int counter = 0;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                    counter++;
                    dfs(visited, um, i);
            } 
        }
        return counter;
        
    }
    void dfs(vector<bool>& visited, vector<vector<int>>& um, int node){
        visited[node] = true;
            for(int i : um[node]){
                if(!visited[i]){
                    dfs(visited, um, i);
                } 
            
        }
    }
};
