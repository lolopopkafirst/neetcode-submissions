class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> acc;
        helper(s, res, acc, 0);
        return res;
    }
    void helper(string& s, vector<vector<string>>& res, vector<string>& acc, int index) {
        if(index == s.size()){
            res.push_back(acc);
            return;
        }
        for(int i = index ; i < s.size() ; i++){
            string cand = s.substr(index, i - index + 1);
            if(isPalindrome(cand)){
                acc.push_back(cand);
                helper(s,res, acc, i + 1);
                acc.pop_back();
            }
        }
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
