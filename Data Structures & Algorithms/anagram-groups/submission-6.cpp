class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> um;
       for(auto& str : strs){
        array<int, 26> word = {};
        for(char c : str){
            word[c - 'a']++;
        }
        string key(word.begin(), word.end());
        um[key].push_back(str);
       }
       
       vector<vector<string>> res;
       for(auto& pair : um){
            res.push_back(pair.second);
       }
       return res;
    }
};