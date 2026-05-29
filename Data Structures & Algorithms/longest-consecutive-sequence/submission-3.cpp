class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 0) return 0;
        int largest = 0;
        int curr = 1;
        for(int i = 1; i < nums.size() ; i++){
            if(nums[i] == nums[i - 1] + 1){
                curr+=1;
                cout<< curr << " and " << nums[i] << " " ;
            }
            else if(nums[i] == nums[i - 1]){
                continue;
            }
            else{
                if(curr > largest) largest = curr;
                curr = 1;
            }
        }
        if(curr > largest) return curr;
        return largest;

        
    }
};
