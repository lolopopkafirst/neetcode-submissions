class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        unordered_map<int, vector<int>> um;
        vector<int> state(numCourses, 0);
        for(auto& v : prerequisites){
            um[v[0]].push_back(v[1]);
        }
        for(int i = 0 ; i < numCourses ; i++){
            cout << i;
            if(!dfs(um, state, i, res)){
                return {};
            }
        }
        return res;
    }

     bool dfs(unordered_map<int, vector<int>>& um, vector<int>& state, int course, vector<int>& res) {
        if(state[course] == 2){
            return true;
        } 
        if(state[course] == 1){
            return false;
        }
        state[course] = 1;
        for(int pre : um[course]){
            if(!dfs(um, state, pre, res)){
                return false;
            }
        }
        state[course] = 2;
        res.push_back(course);
        return true;
     }
};
