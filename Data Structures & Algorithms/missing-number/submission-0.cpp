class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        if(n % 2 == 0){
            sum = (1 + n) * (n / 2);
        }
        else{
            sum = (1 + n) * (n / 2) + (n / 2) + 1;
        }
        int curr = 0;
        for(int i : nums){
            curr += i;
        }
        
        return sum - curr;
    }
};
