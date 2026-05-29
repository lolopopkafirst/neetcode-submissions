class Solution {
public:
bool checkInclusion(string s1, string s2) {
    int n = s1.size();
    array<int, 26> um{};
    int nonzero = 0;

    for(char c : s1){
        if(um[c - 'a']++ == 0)nonzero++;
    }

    int l = 0;
    for(int r = 0; r < s2.size() ; r++){
        um[s2[r] - 'a']--;
        if(um[s2[r] - 'a'] == 0){
            nonzero--;
        }
        else if(um[s2[r] - 'a'] == -1){
            nonzero++;
        }
        if(r - l + 1 == n){
            if(nonzero == 0) return true;
            um[s2[l] - 'a']++;
            if (um[s2[l] - 'a'] == 1) nonzero++;
            else if (um[s2[l] - 'a'] == 0) nonzero--;
            l++;
        }
    }
    return false;

}
};