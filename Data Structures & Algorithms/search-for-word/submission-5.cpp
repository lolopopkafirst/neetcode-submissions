class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<char>> visited = board;
        for(int y = 0 ; y < board.size() ; y++){
            for(int x = 0 ; x < board[y].size() ; x++){
                if(board[y][x] == word[0]){
                    if(helper(board, visited, word, x, y, 0)){
                        cout << "GOAL" << x << y;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& board, vector<vector<char>>& visited, string& word, int x, int y, int index) {
        if(x < 0 || y < 0 || x >= board[0].size() || y >= board.size()) return false;
        if(visited[y][x] == '#') return false;
        if(x == 0 && y == board.size()) return false;
        if(board[y][x] == word[index]){
            visited[y][x] = '#';
            index += 1;
        }
        else {
            return false;
        }
        if(index == word.size()){
            return true;
        } 
        if(helper(board, visited, word, x + 1, y, index) || helper(board, visited, word,  x - 1, y, index) || helper(board, visited, word,  x, y + 1, index) || helper(board, visited, word, x, y - 1, index)){
            return true;
        }
        else{
            visited[y][x] = 'X';
            return false;
        } 
        
        
        
    }

};
