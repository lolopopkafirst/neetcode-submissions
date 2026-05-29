class Solution {
public:
    bool isPalindrome(string s) {
        int right = s.length() - 1;
        int left = 0;
        while(left < right){
            while(left < right && !isalnum(s[left])){
                left++;
            }
            while(left < right && !isalnum(s[right])){
                right--;
            }
            if(tolower(s[right]) != tolower(s[left])) return false;
            left++;
            right--;

        }  
        return true; 
        }
};
