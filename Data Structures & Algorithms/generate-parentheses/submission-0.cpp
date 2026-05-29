class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> res;
        helper (n, n, str, res);
        return res; 
    }
    void helper(int l, int r, string& str, vector<string>& res) {
        if(l == 0 && r == 0){
            res.push_back(str);
            return;
        }
        if(l == r){
            str += "(";
            helper(l - 1, r, str, res);
            str.erase(str.length() - 1);
        }
        else if(l < r && l != 0 && l > 0){
            str += "(";
            helper(l - 1, r, str, res);
            str.erase(str.length() - 1);
            str += ")";
            helper(l, r - 1, str, res);
            str.erase(str.length() - 1);
        }
        else if(l == 0 && r > 0){
             str += ")";
             helper(l, r - 1, str, res);
             str.erase(str.length() - 1);
             
        }
        

            
        

       
    }
};
