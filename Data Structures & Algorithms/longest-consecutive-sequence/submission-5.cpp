class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set <int> us (nums.begin(), nums.end());
       int largest = 0;
       for(int num : us){
        if(us.count(num - 1)) continue;
        int curr = 1;
        while(us.count(++num)){
                curr++;
               
        }
        if(curr > largest) largest = curr;
       }
       return largest;
    }
};
