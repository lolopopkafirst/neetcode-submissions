class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length()) return false;
        vector<vector<int>> memo(s1.size() + 2, vector<int>(s2.size() + 2, -1));

        return rek(-1, -1, -1, s1, s2, s3, false, false, memo);
    }
    bool rek(int id1, int id2, int id3, string& s1, string& s2, string& s3, bool first, bool second, vector<vector<int>>& memo){
        
        // cout << id1 <<  ", " << id2 << ", " << id3 << "\n";
        if(id3 >= (int)s3.length()){
            // cout << id3 << " >= " << s3.length() << " = " << (id3 >= s3.length()) << "\n" << (-1 >= 6);
            // cout << "END";
            return true;
        }
        if(memo[id1 + 1][id2 + 1] != -1) return memo[id1 + 1][id2 + 1];
        if(first){
            if(id1 >= (int) s1.length()) return false;
            if(s1[id1] == s3[id3]){
                memo[id1 + 1][id2 + 1] = rek(id1, id2, id3, s1, s2, s3, false, false, memo);
                return memo[id1 + 1][id2 + 1];
            }
            else {
                return false;
            }
        }
        if(second){
            if(id2 >= (int) s2.length()) return false;
            if(s2[id2] == s3[id3]){
                memo[id1 + 1][id2 + 1] = rek(id1, id2, id3, s1, s2, s3, false, false, memo);
                return memo[id1 + 1][id2 + 1];
            }
            else {
                return false;
            }
        }
        bool takefirst = rek(id1 + 1, id2, id3 + 1, s1, s2, s3, true, false, memo);
        bool takesecond = rek(id1, id2 + 1, id3 + 1, s1, s2, s3, false, true, memo);
        memo[id1 + 1][id2 + 1] = takefirst || takesecond;
        return memo[id1 + 1][id2 + 1];
    }

};
