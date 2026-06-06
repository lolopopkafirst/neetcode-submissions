class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = 0;
        int m = 0;
        for(size_t y{} ; y < grid.size() ; ++y){
            for(size_t x{} ; x < grid[y].size() ; ++x){
                if(grid[y][x]){
                    cout << "lol";
                    m = max(helper(grid, x, y), m);
                }
            }
        }
        return m;
    }

    int helper (vector<vector<int>>& grid, int x, int y){
        if(y < 0 || y >= grid.size() || x < 0 || x >= grid[y].size() || grid[y][x] == 0) return 0;
        grid[y][x] = 0;
        return 1 + helper(grid, x + 1, y) + helper(grid, x - 1, y) + helper(grid, x, y + 1) + helper(grid, x, y - 1) ;
    }
};
