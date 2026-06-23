class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int len = 0;
            for(int i = 0 ; i < s.size() ; ++i){
                int right = i;
                int left = i;
                while(left >= 0 && right < s.size() && s[right] == s[left]){   
                    // cout << left << " " << right << "\n";
                    if(right - left + 1 > len) {
                        // cout << left << " " << right << "\n";
                        start = left;
                        len = right - left + 1;
                    }
                    left--;
                    right++;
                }
                right = i + 1;
                left = i;
                while(left >= 0 && right < s.size() && s[right] == s[left]){   
                    // cout << left << " " << right << "\n";
                    if(right - left + 1 > len) {
                        // cout << left << " " << right << "\n";
                        start = left;
                        len = right - left + 1;
                    }
                    left--;
                    right++;
           }
        }
        return s.substr(start, len);
    }
};