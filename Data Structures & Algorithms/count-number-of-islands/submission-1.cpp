class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        vector<vector<char>> visited(grid);
        for(int i = 0 ; i < grid.size() ; i++){
            for (int j = 0 ; j < grid[i].size() ; j++){
                if(grid[i][j] == '1'){
                    helper(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    void helper(vector<vector<char>>& grid, int i, int j){
        if(i >= grid.size() || i < 0 || j < 0 || j >= grid[i].size() || grid[i][j] == '0') return;
        if(grid[i][j] == '1') grid[i][j] = '0';
        helper(grid, i + 1, j);
        helper(grid, i, j + 1);
        helper(grid, i - 1, j);
        helper(grid, i, j - 1);
    }
};
