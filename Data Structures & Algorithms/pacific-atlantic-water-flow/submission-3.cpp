class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        for(int row = 0 ; row < heights.size() ; ++row){
            for(int col = 0 ; col < heights[row].size() ; ++col){
                bool i = false;
                bool ii = false;
                vector<vector<int>> visited(heights);
                if(pacific(heights, row, col, i, ii, INT_MAX, visited)){
                    res.push_back({row, col});
                }
            }
        }
        return res;
    }
    bool pacific(vector<vector<int>>& heights, int row, int col, bool& pacificP, bool& atlantic, int prev1, vector<vector<int>>& visited) {
        if(row < 0 || row >= heights.size() || 
        col < 0 || col >= heights[row].size() || prev1 < heights[row][col] || visited[row][col] == -1){
            return pacificP && atlantic;
        }
        if(row == 0 || col == 0){
            pacificP = true;
        }
        if(row == heights.size() - 1 || col == heights[0].size() - 1){
            atlantic = true;
        } 
        int prev = heights[row][col];
        visited[row][col] = -1;
        
        return pacific(heights, row + 1, col, pacificP, atlantic, prev, visited) ||
        pacific(heights, row, col + 1, pacificP, atlantic, prev, visited) ||
        pacific(heights, row, col - 1, pacificP, atlantic, prev, visited) ||
        pacific(heights, row - 1, col, pacificP, atlantic, prev, visited);

        
    }
};
