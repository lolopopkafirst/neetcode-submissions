class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> first;
        unordered_map <char, int> second;
        if(s.size() == t.size()){
            for(int i = 0; i< s.size() ; i++){
                first[s[i]]++;
                second[t[i]]++;
            }
            return second == first;
        }
        return false;
    }
};
