class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size() >= text2.size()){
            swap(text1, text2);
        }
        vector<vector<int>> memo(text2.size(), vector<int>(text1.size(), 0));
        return rek(text1, text2, 0, 0, memo);
    }
    int rek(string& text1, string& text2, int index1, int index2, vector<vector<int>>& visited){
        if(index2 >= text2.size() || index1 >= text1.size()){
            return 0;
        }
        if(visited[index2][index1] != 0){
            return visited[index2][index1];
        }
        if(text1[index1] == text2[index2]){
            return rek(text1, text2, index1 + 1, index2 + 1, visited) + 1;
        }
        else{
            visited[index2][index1] = max(rek(text1, text2, index1, index2 + 1, visited), rek(text1, text2, index1 + 1, index2, visited));
        }
        return visited[index2][index1];
    }


    

};
