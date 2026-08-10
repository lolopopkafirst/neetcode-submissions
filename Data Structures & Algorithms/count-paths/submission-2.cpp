class Solution {
public:
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        return down(0, 0, m, n, visited);        
    }
    int down(int x, int y, int m, int n, vector<vector<int>>& visited){
        if(x >= m || y >= n) return 0;
        cout << "x = " << x << " y = " << y << "\n";
        if((x == m - 1 && y == n - 1)){
            return 1;
        }
        if(visited[x][y] != 0){
            return visited[x][y];
        }
        visited[x][y] = down(x + 1, y, m, n, visited) + down(x, y + 1, m, n, visited);
    return visited[x][y];
    }
};
