class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res((matrix.size() * matrix[0].size()), 0);
        int counter = 0;
        int layers = (min(matrix.size(), matrix[0].size()) + 1) / 2;
        for(int layer = 0 ; layer < layers ; layer++){
        int right = matrix[0].size() - layer;
        int left = layer;
        int down = matrix.size() - layer;
        for(int i = left ; i < right; i++){
            res[counter++] = matrix[left][i];
        }
        for(int i = left + 1 ; i < down; i++){
            res[counter++] = matrix[i][right - 1];
        }
        if(down - 1 != left){
            for(int i = right - 2 ; i >= left ; i--){
                res[counter++] = matrix[down - 1][i];
            }
        }
        if(right - 1 != left){
            for(int i = down - 2 ; i >= left + 1 ; i--){
                res[counter++] = matrix[i][left];
            }
        }
        }
        return res;
    }
};
