class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int cals = matrix.size();

        int raws = matrix[0].size();
        
        int r = (cals * raws) - 1;
        int mid = 0;
        while(l <= r){
            mid = l + ((r - l + 1) / 2);
            cout << " mid = "<< mid << "| ";
            cout << " value =  "<< matrix[mid / raws][mid % (raws)] << "| ";
            if(matrix[mid / raws][mid % (raws)] == target){
                return true;
            }
            else if(matrix[mid / raws][mid % (raws)] > target){
                r = mid - 1;
                cout << " r = "<< r << "| ";
            } else{
                l = mid + 1;
                cout << " l = "<< l << "| ";
            }
        }
        return false;
        
    }
};
