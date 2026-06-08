class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        for(size_t i = 0 ; i < grid.size(); ++i){
            for(size_t j = 0 ; j < grid[i].size(); ++j){
                if(grid[i][j] == 0){
                    vector<vector<int>> visited(grid);
                    helper(grid, i, j, 0, visited);
                } 
            }   
        }
    }
    void helper(vector<vector<int>>& grid, size_t row, size_t col, int step, vector<vector<int>>& visited){
         cout << "row, "<< row << " col, "<< col << " step, " << step << "\n";
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size() || grid[row][col] == -1 || visited[row][col] == -1){
            return;
        }
        if(step != 0 && grid[row][col] == 0){
            return;
        }
        if(step > 0 && step >= grid[row][col]){
            return;
        }
        if(step > 0) {
            grid[row][col] = step;
        }
        helper(grid, row + 1, col, step + 1, visited);
        helper(grid, row - 1, col, step + 1, visited);
        helper(grid, row, col - 1, step + 1, visited);
        helper(grid, row, col + 1, step + 1, visited);
    
    }
};
