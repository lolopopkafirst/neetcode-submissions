class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> um;
        vector<int> state(numCourses, 0);
        for(auto& v : prerequisites){
            um[v[0]].push_back(v[1]);
        }
        for(int i = 0 ; i < numCourses ; ++i){
            if(!dfs(um, state, i)){
                return false;
            }
        }
        return true;
    }

    bool dfs(unordered_map<int, vector<int>>& um, vector<int>& state, int course ){
        if(state[course] == 1) return false;
        if(state[course] == 2) return true;
        state[course] = 1;
        for(int i : um[course]){
            if(!dfs(um, state, i)){
                return false;
            }
        }
        state[course] = 2;
        return true;
    }

};
