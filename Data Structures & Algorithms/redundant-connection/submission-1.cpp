class Solution {
private:
    int find(int node, vector<int>& parent){
        int cur = node;
        while(cur != parent[cur]){
            parent[cur] = parent[parent[cur]];
            cur = parent[cur];
        }
        return cur;
    }

    bool unionf(int u, int v, vector<int>& parent, vector<int>& rank){
        int pu = find(u, parent);
        int pv = find(v, parent);
        if(pu == pv) return false;
        if(rank[pv] > rank[pu]){
            swap(pv, pu);
        }
        parent[pv] = pu;
        rank[pu] += rank[pv];
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 1);

        for(int i = 0 ; i < n; ++i){
            parent[i] = i;
        }
        for(auto& vec : edges){
            int u = vec[0];
            int v = vec[1];
            if(!unionf(u, v, parent, rank)){
                return vec;            
            }
        }
        return {};
    }
    
};
