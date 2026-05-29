class Solution {
public:
    vector<string> board;
    vector<vector<string>> solveNQueens(int n) {
         board.resize(n, string(n, '.'));
         vector<vector<string>> res;
         helper(board, 0, 0, n, 0, res );
         return res;
    }


    void helper(vector<string>& board, int x, int y, int& target, int count, vector<vector<string>>& res ) {
        if(count == target){
            res.push_back(board);
            return;
        } 
        if(x == target){
            x = 0;
            y++;
        }
        if(y == target){
            return;
        }
        if(checkVertical(board, x, y) && checkHorizontal(board, x, y) && checkDiagonal(board, x, y)){
            count++;
            board[y][x] = 'Q';
            helper(board, x + 1, y, target, count, res);
            count--;
            board[y][x] = '.';
            helper(board, x + 1, y, target, count, res);
        }
        else{
            helper(board, x + 1, y, target, count, res);
        }
        
        
    }


    bool checkVertical(vector<string> board, int x , int y){
        for (int i = 0; i < board.size(); i++){
            if(board[i][x] == 'Q') return false;
        }
        return true;
        
    }
    bool checkHorizontal(vector<string> board, int x , int y){
        for (int i = 0; i < board.size(); i++){
            if(board[y][i] == 'Q') return false;
        }
        return true;
    }
    bool checkDiagonal(vector<string> board, int x , int y){
        int tempx = x;
        int tempy = y;
        while(tempx >= 0 && tempy >= 0){
            if(board[tempy][tempx] == 'Q') return false;
            tempx--;
            tempy--;
        }
        tempx = x;
        tempy = y;
        while(tempx < board.size() && tempy < board.size()){
            if(board[tempy][tempx] == 'Q') return false;
            tempx++;
            tempy++;
        }
        tempx = x;
        tempy = y;
        while(tempx >= 0 && tempy < board.size()){
            if(board[tempy][tempx] == 'Q') return false;
            tempx--;
            tempy++;
        }
        tempx = x;
        tempy = y;
        while(tempx < board.size() && tempy >= 0){
            if(board[tempy][tempx] == 'Q') return false;
            tempx++;
            tempy--;
        }
        return true;
    }
    
};
