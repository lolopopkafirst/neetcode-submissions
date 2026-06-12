class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty()) return true;
        unordered_map<int, vector<int>> pre;
        vector<int> state(numCourses, 0);
        for(int i = 0; i < numCourses ; i++){
            pre[i] = {};
        }
        for(auto& v : prerequisites){
            pre[v[0]].push_back(v[1]);
        }
        
        for(int i = 0 ; i < numCourses ; i++){
            if(!dfs(pre, state, i)){
                return false;
            }
        }
        return true;


    }
    bool dfs(unordered_map<int, vector<int>>& pre, vector<int>& state, int course) {
        if(state[course] == 1) return false;
        if(state[course] == 2){
            return true;
        }
        if(pre[course].empty()){
            state[course] = 2;
            return true;
        }
  
        else state[course] = 1;
        for(int i : pre[course]){
            if(!dfs(pre, state, i)){
                return false;
            }
        }
        state[course] = 2;
        return true;


    }

};
