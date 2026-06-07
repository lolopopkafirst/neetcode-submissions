class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        return helper(s, res, 0, 0);
        
    }
     int helper(string& s, int& res, int l, int r) {
        if(r >= s.size()){
            l++;
            r = l;
        } 

        if(l >= s.size()) return res;
        
        if(reversed(s, l, r)){
            res++;
        } 
        return helper(s, res, l, r + 1);
    
    }
    bool reversed(string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
