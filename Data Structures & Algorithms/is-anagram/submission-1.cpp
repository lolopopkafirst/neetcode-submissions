class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> first;
        unordered_map <char, int> second;
        if(s.size() == t.size()){
            for(char i : s){
               first[i]++;
            }
             for(char i : t){
                second[i]++;
            }
            for(auto [ch, val] : first){
                if(val != second[ch]) return false;
            }
            return true;
        }
        return false;
    }
};
