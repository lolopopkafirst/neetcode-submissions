class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);
 
        return dfs(s, wordDict, 0, memo);
       
    }
    bool dfs(string& s, vector<string>& wordDict, int start, vector<int>& memo){
        if(start == s.size()){
            return true;
        }
        if(memo[start] != -1) return memo[start];
        for(auto& str : wordDict){
             if (start + str.size() > s.size()) continue;
             bool found = true;
            for(int i = 0 ; i < str.size() ; i++){
                if(str[i] != s[start + i]){
                    found = false;
                    break;
                }
            }
            if(found && dfs(s, wordDict, start + str.size(), memo)){
                return memo[start] = 1;
            }
        }
        return memo[start] = 0;
    }
};
