class Solution {
public:
    vector<string> chars = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if(digits == "") return {}; 
        vector<string> res;
        string acc;
        helper(digits, res, acc, 0);
        return res;
    }
    void helper(string digits, vector<string>& res, string& acc, int index) {
        if(index == digits.size()){
            res.push_back(acc);
            return;
        }
        for(int i = 0 ; i < chars[digits[index] - '0'].size(); i++){
            acc.push_back(chars[digits[index] - '0'][i]);
            helper(digits, res, acc, index + 1);
            acc.pop_back();
        }
    }
};
