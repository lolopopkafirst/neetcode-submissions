class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> acc;
        if (s.empty()) return res;
        acc.push_back(string(1, s[0]));
        helper(s, res, acc, 1);
        return res;
    }
    void helper(string& s, vector<vector<string>>& res, vector<string>& acc, int index) {
        if(index == s.size()){
            for(string str : acc){
                if(!isPalindrome(str)){
                    return;
                }
            }
            res.push_back(acc);
            return;
        }
        // Option 1: start new substring
        acc.push_back(string(1, s[index]));
        helper(s, res, acc, index + 1);
        acc.pop_back();

        // Option 2: append current char to previous substring
        acc.back().push_back(s[index]);
        helper(s, res, acc, index + 1);
        acc.back().pop_back();

    }

    bool isPalindrome(string str){
        int l = 0;
        int r = str.size() - 1;
        while(l < r){
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
}; 