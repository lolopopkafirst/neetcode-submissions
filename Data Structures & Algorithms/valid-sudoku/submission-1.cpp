class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       unordered_map <int,  unordered_map <char, int>> raws;
       unordered_map <int,  unordered_map <char, int>> cals;
       unordered_map <int,  unordered_map <char, int>> blocks;

        for(int i = 0 ; i < 9 ; i++){
            for(int k = 0 ; k < 9 ; k++){

                if(board[i][k] == '.') continue;
                int blockid = (i / 3) * 3 + (k / 3);
                cout << blockid;
                raws[i][board[i][k]]++;
                cals[k][board[i][k]]++;
                blocks[blockid][board[i][k]]++;
        }
        for(auto& [num , um] : raws){
            for(auto& [num , val] : um){
                if(val > 1) return false;
        }
        }
        for(auto& [num , um] : blocks){
            for(auto& [num , val] : um){
                if(val > 1) return false;
        }
        }
        for(auto& [num , um] : cals){
            for(auto& [num , val] : um){
                if(val > 1) return false;
        }
        }
        }

        return true;
    }
};
