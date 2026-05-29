class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        bool flag = true;
        int n = s1.size();
        unordered_map <char, int> um;
        for(char c : s1){
            um[c]++;
        }
        int l = 0;
        for(int r = 0; r < s2.size() ; r++){
            um[s2[r]]--;
            if(((r - l) + 1) % s1.size() == 0){
                for(auto&[c, i] : um){
                    if(i != 0){
                        flag = false;
                        break;
                    } 
                }
                if(flag) return true;
                flag = true;
                um[s2[l]]++;
                l++;
            }
        }
        return false;
    }
};
