class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int counter[26] = {0};
        int m = 0;
        int result = 0;
        for(int r = 0 ; r < s.size() ; r++){
            counter[s[r] - 'A']++;
            m = max(m, counter[s[r] - 'A']);
            while(((r - l + 1) - m) > k){
                counter[s[l] - 'A']--;
                l++;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};
