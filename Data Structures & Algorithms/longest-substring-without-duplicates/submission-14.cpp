class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
 
        int l = 0;
        int result = 0;
        for(int r = 0 ; r < s.size() ; r++){
            if(seen[s[r]] != 0){
                l = max(l, seen[s[r]]);
            }
            result = max(result, r - l + 1);
            seen[s[r]] = r + 1;
        }
        
        return result;

        
    }
};
