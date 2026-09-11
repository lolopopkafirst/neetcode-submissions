class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), -1));
        return rek(word1, word2, 0, 0, memo);
    }
    int rek(string& word1, string& word2, int index1, int index2, vector<vector<int>>& memo){
        
        if(index1 >= word1.size()){    
            return word2.length() - index2;
        }
        if(index2 >= word2.size()){
            return word1.length() - index1;
        }
        if(memo[index1][index2] != -1) return memo[index1][index2];
        if(word1[index1] == word2[index2]){
            memo[index1][index2] =  rek(word1, word2, index1 + 1, index2 + 1, memo);
            return memo[index1][index2];
        }
        else{
            int rep = 1 + rek(word1, word2, index1 + 1, index2 + 1, memo);
            int del = 1 + rek(word1, word2, index1 + 1, index2, memo);
            int ins = 1 + rek(word1, word2, index1, index2 + 1, memo);
            memo[index1][index2] = min({rep, del, ins});
            return memo[index1][index2];
        }
    
    }
};
