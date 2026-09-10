class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> memo(s.size() + 1, vector<int>(t.size() + 1, -1));
        return rek(s, t, 0, 0, memo);

    }
    int rek(string& s, string& t, int indexS, int indexT, vector<vector<int>>& memo){
        if(indexS >= s.length() && indexT < t.length() ){
            memo[indexS][indexT] = 0;
            return 0;
        } 
        if(indexT >= t.length()){
            memo[indexS][indexT] = 1;
            return 1;
        } 
        if(memo[indexS][indexT] != -1){
            return memo[indexS][indexT];
        }
        int take = 0;
        int notTake = 0;
        if(s[indexS] == t[indexT]){
            take = rek(s, t, indexS + 1, indexT + 1, memo);
            //cout << s[indexS] << ' ' << t[indexT] << "\n";
        }
        notTake = rek(s, t, indexS + 1, indexT, memo);
        memo[indexS][indexT] = take + notTake;
        return memo[indexS][indexT];
    }
};
