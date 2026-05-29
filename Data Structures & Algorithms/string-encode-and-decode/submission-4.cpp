class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string str : strs){
            res += str + "/new_line/";
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string word = "";

            for(int i = 0 ; i < s.size(); i++){
                cout << s[i];
                if(s[i] != '/'){
                    word+=s[i];
                } else{
                    if(s[i + 9] != '/'){
                         word+=s[i];
                    }
                    else{
                    res.push_back(word);
                    word = "";
                    i += 9;
                    }
                    
                }
            }
            return res;
    }
};
