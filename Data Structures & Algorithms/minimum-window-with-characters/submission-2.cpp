class Solution {
public:
    string minWindow(string s, string t) {
        int n = t.size();
        unordered_map<char, int> um;
        int nonzero = 0;
        for(char c : t){
            if(um[c]++ == 0) nonzero++;
        }

        int l = -1;
        int m = 0; //min sequence
        string res = "";
        vector<char> cur;
        for(int r = 0 ; r < s.size() ; r++){
            while((um.find(s[r]) == um.end()) && l == -1 && r < s.size()){
                r++;
            }
            if(l == -1){
                l = r;
            }
            cur.push_back(s[r]);
            if(!(um.find(s[r]) == um.end())){
                if(--um[s[r]] == 0){
                    nonzero--;
                } 
            }  
            cout << " | " << s[l] << " : "<< s[r] << ", " << nonzero <<  " | ";
            if(nonzero == 0){
                for(char c : cur){
                    cout << c;
                }
            }
            while(nonzero == 0){
                if(res.size() > cur.size() || res.size() == 0){
                    res = "";
                    for(char c : cur){
                        res+=c;
                    }
                }
                    um[s[l]]++;
                    if(um[s[l]] == 1) nonzero++;
                    l++;
                cur.erase(cur.begin());
                while((um.find(s[l]) == um.end())){
                    l++;
                    cur.erase(cur.begin());
                }
            }    
        }
        return res;
    }
};
