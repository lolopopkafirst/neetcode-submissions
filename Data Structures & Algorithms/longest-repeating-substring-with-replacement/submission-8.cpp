class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        unordered_map<char, int> um;
        int m = 0;
        int result = 0;
        for(int r = 0 ; r < s.size() ; r++){
            um[s[r]]++;
            m = max(m, um[s[r]]);
            while((r - l + 1 - m) > k){
                um[s[l]]--;
                l++;
            }
            result = max((r - l + 1), result);
        }
        return result;
    }
};
