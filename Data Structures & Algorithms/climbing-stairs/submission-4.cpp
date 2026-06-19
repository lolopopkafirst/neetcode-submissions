class Solution {
public:
    int climbStairs(int n) {
       vector<int> arr(3, 0);
       arr[0] = 1;  
       for(int i = 0; i < n ; ++i){
            arr[1] += arr[0];
            arr[2] += arr[0];
            arr[0] = arr[1];
            arr[1] = arr[2];
            arr[2] = 0;
       }
       for(int i = 0 ; i < 3 ; i++){
        cout << arr[i];
       }
       return arr[0];
    }

};