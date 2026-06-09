class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<vector<int>> q;
        for(int row = 0 ; row < grid.size() ; ++row){
            for(int col = 0 ; col < grid[row].size() ; ++col){
                if(grid[row][col] == 2){
                    q.push({row, col, 0});
                }
            }
        }
        vector<pair<int, int>> arr = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int res = 0;
        while(!q.empty()){
            int r = q.front()[0];
            int c = q.front()[1];
            int temp = q.front()[2];
            q.pop();
            for(int i = 0 ; i < 4 ; ++i){
                int row = r + arr[i].first;
                int col = c + arr[i].second;
                if(row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size() || grid[row][col] == 0 ||  grid[row][col] == 2){
                    continue;
                }
                grid[row][col] = 2;
                q.push({row, col, temp + 1});
            }
            res = max(res, temp);
        }
        for(size_t row = 0 ; row < grid.size() ; ++row){
            for(size_t col = 0 ; col < grid[row].size() ; ++col){
                if(grid[row][col] == 1){
                    return -1;
                }
            }
        }
        return res;
 
    }

  
};
