class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i = 0 ; i < heights.size(); i++){
            dfs(heights, i, 0, pacific, directions);
            dfs(heights, i, heights[0].size() - 1, atlantic, directions);
        }
        for(int i = 0 ; i < heights[0].size(); i++){
            dfs(heights, 0, i, pacific, directions);
            dfs(heights, heights.size() - 1, i, atlantic, directions);
        }

        for(int row = 0; row < heights.size() ; ++row){
            for(int col = 0; col < heights[0].size() ; ++col){
                if(atlantic[row][col] && pacific[row][col]){
                    res.push_back({row, col});
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& heights, int row, int col, vector<vector<bool>>& ocean, vector<vector<int>>& directions) {
       ocean[row][col] = true;
        for(auto& i : directions){
            int r = row + i[0];
            int c = col + i[1];
        
            if(r < 0 || r >= heights.size() || c < 0 || c >= heights[r].size() ||
            heights[r][c] < heights[row][col] || ocean[r][c])
            {
          
                continue;
            }
            dfs(heights, r, c, ocean, directions);
        }
    }
};
