class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> seted(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[i].size() ; j++){
                if(matrix[i][j] == 0 && !seted[i][j]){
                    // cout << i << " " << j;
                    placeZero(matrix, seted, i, j);
                }
            }
        }
        
    }
    void placeZero(vector<vector<int>>& matrix, vector<vector<int>>& seted, int row , int col){
        for(int i = 0 ; i < matrix[row].size() ; i++){
            if(matrix[row][i] != 0 ){
                seted[row][i] = 1;
                matrix[row][i] = 0;
            }
        }
         for(int i = 0 ; i < matrix.size() ; i++){
            if(matrix[i][col] != 0 ){
                seted[i][col] = 1;
                matrix[i][col] = 0;
            }
        }
    }
};
