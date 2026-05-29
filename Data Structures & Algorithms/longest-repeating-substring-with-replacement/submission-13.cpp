class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        array<int, 26> um{};
        int m = 0;
        int result = 0;
        for(int r = 0 ; r < s.size() ; r++){
            um[s[r] - 'A']++;
            m = max(m, um[s[r] - 'A']);
            while((r - l + 1 - m) > k){
                um[s[l] - 'A']--;
                l++;
            }
            result = max((r - l + 1), result);
        }
        return result;
    }
};
