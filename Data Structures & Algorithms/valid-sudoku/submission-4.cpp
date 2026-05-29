class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       bool raws[9][9] = {};
       bool cals[9][9] = {};
       bool blocks[9][9] = {};

        for(int i = 0 ; i < 9 ; i++){
            for(int k = 0 ; k < 9 ; k++){
                if(board[i][k] == '.') continue;
                int blockid = (i / 3) * 3 + (k / 3);
                int num = board[i][k] - '1';
                if(raws[i][num] || cals[k][num] || blocks[blockid][num]) return false;
                raws[i][num] = true;
                cals[k][num] = true;
                blocks[blockid][num] = true;
        }
        
        }

        return true;
    }
};
