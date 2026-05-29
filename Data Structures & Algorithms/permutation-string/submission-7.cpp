class Solution {
public:
bool checkInclusion(string s1, string s2) {
int n = s1.size();
array<int, 26> um{};
int nonzero = 0;
for(char c : s1){
if(um[c - 'a']++ == 0) nonzero++; 
}
int l = 0;
for(int r = 0; r < s2.size() ; r++){
int ind = s2[r] - 'a';
if(um[ind] == 1) nonzero--;        // 1→0
else if(um[ind] == 0) nonzero++;   // 0→-1
            um[ind]--;
if(r - l + 1 == n) {
if(nonzero == 0) return true;
int li = s2[l] - 'a';
if(um[li] == -1) nonzero--;         // -1→0: стало нулевым
else if(um[li] == 0) nonzero++;     // 0→1: стало ненулевым
                um[li]++;
                l++;
}
}
return false;
}
};