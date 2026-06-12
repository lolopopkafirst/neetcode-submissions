class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<char>> visited(board);
        for(int row = 0 ; row < board.size() ; ++row){
 
           if(board[row][0] == 'O'){
               dfs(board, row, 0, visited);     
            }
            if(board[row][board[0].size() - 1] == 'O'){
                dfs(board, row, board[0].size() - 1, visited);
            }
        }
         for(int col = 0 ; col < board[0].size() ; ++col){
            if(board[0][col] == 'O'){
                dfs(board, 0, col, visited);
            }
            if(board[board.size() - 1][col] == 'O'){
                dfs(board, board.size() - 1, col, visited); 
            }
        }

        for(int row = 0 ; row < board.size() ; ++row){
            for(int col = 0 ; col < board[row].size() ; ++col){
                cout << board[row][col] << " " << visited[row][col] << "\n";
                if(board[row][col] != 'X' && board[row][col] == visited[row][col]){
                    board[row][col] = 'X';
                }
            }
        }

    }
    void dfs(vector<vector<char>>& board, int row, int col , vector<vector<char>>& visited){
        if(row < 0 || row >= board.size() || col < 0 ||
         col >= board[0].size() || visited[row][col] == 'N' || board[row][col] == 'X'){
            return;
        }
        visited[row][col] = 'N';
        dfs(board, row + 1, col, visited);
        dfs(board, row - 1, col, visited);
        dfs(board, row, col + 1, visited);
        dfs(board, row, col - 1, visited);
    }
};
