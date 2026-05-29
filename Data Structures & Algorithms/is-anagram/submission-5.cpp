class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> count;
    
        if(s.size() == t.size()){
            for(int i = 0; i< s.size() ; i++){
                count[s[i]]++;
                count[t[i]]--;
            }
            for(auto& [ch, val] : count){
                if(val != 0) return false;
            }
            return true;
        }
        return false;
    }
};
