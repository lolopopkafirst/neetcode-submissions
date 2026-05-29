class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        if(s.size() == 1) return 1;
        int l = 0;
        int result = 0;
        for(int r = 1 ; r < s.size() ; r++){
            if(seen.empty()){
                seen[s[l]] = l + 1;
            }
            if(seen[s[r]] != 0){
                result = max(result, r - l);
                l = max(l,seen[s[r]]);
                seen[s[r]] = r + 1;
                
                
            }
            else{
                seen[s[r]] = r + 1;
            }
        }
        int m = s.size();
        result = max(result, m - l);
        return result;

        
    }
};
