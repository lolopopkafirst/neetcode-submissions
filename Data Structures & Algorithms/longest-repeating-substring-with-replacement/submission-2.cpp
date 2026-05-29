class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int result = 0;
        int count[26] = {0};
        int maxf = 0;
        for(int r = 0 ; r < s.size() ; r++){
            count[s[r] - 'A']++;
            maxf = max(maxf, count[s[r] - 'A']);
             while ((r - l + 1) - maxf > k) {
                count[s[l] - 'A']--;
                l++;
            }
            result = max(result, r - l + 1);
        }
      
          return result;
    }
};
