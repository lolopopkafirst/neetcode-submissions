class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string str : strs){
            res += to_string(str.size()) + "#" + str;
        }
        cout<<res;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string word = "";

            for(int i = 0 ; i < s.size(); i++){
                int curr = 0;
                word = "";
                cout << s[i];
                while(s[i] != '#'){
                    curr *= 10;
                    curr += s[i] - 48;
                    i++;
                }
                i++;
                for(int k = i; k < i + curr; k++){
                    word += s[k];
                }
                i += curr - 1;
                res.push_back(word);
            }
            return res;
    }
};
