class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set <int> us (nums.begin(), nums.end());
       int largest = 0;
       for(int num : us){
        if(us.count(num - 1)) continue;
        int curr = 1;
        for(int i = 0 ; i < us.size() ; i++){
            if(us.count(num + 1)){
                curr++;
                num++;
            } else break;
        }
        if(curr > largest) largest = curr;
       }
       return largest;
    }
};
