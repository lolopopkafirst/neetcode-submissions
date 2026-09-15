class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
 
        for(int layer = 0 ; layer < n / 2 ; layer++){
            int left = layer;
            int right = n - layer;
            int temp = 0;
            int prev = 0;
            int side = right - left;
            for(int d = 0; d < side - 1 ; d++){
                for(int i = left ; i < right ; i++){
                    temp = matrix[left][i];
                    matrix[left][i] = prev;
                    prev = temp;
                }
                for(int i = left + 1 ; i < right ; i++){
                    temp = matrix[i][right - 1];
                    matrix[i][right - 1] = prev;
                    prev = temp;
                }
                for(int i = right - 1 - 1 ; i >= left ; i--){
                    temp = matrix[right - 1][i];
                    matrix[right - 1][i] = prev;
                    prev = temp;
                }
                for(int i = right - 1 - 1 ; i >= left ; i--){
                    temp = matrix[i][left];
                    matrix[i][left] = prev;
                    prev = temp;
                }
                
                }
            }
        }
    };
