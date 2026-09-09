class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 0));
        int res = 0;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[i].size() ; j++){
                int x = rek(matrix, j, i, 0, -1, memo);
                res = max(x, res);
            }
            
        }
        return res;
    }
    int rek(vector<vector<int>>& matrix, int x, int y, int res, int prev, vector<vector<int>>& memo) {
        if(y >= matrix.size() || x < 0 || y < 0 || x >= matrix[y].size() || prev >= matrix[y][x])     { 
            return 0;
        }
        if(memo[y][x] != 0) return memo[y][x];
        int goleft = 1 + rek(matrix, x - 1, y, res, matrix[y][x], memo);
        int goright = 1 + rek(matrix, x + 1, y, res, matrix[y][x], memo);
        int godown = 1 + rek(matrix, x, y + 1, res, matrix[y][x], memo); 
        int goup = 1 + rek(matrix, x, y - 1, res, matrix[y][x], memo); 
        memo[y][x] = max(max(goleft, goright), max(godown, goup));
        return memo[y][x];
    }
};
