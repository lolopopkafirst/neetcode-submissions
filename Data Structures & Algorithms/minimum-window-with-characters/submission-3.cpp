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
        int res = INT_MAX;
        int strt = 0;
        for(int r = 0 ; r < s.size() ; r++){
            while((um.find(s[r]) == um.end()) && l == -1 && r < s.size()){
                r++;
            }
            if(l == -1){
                l = r;
            }
            //cur.push_back(s[r]);

      
            if(!(um.find(s[r]) == um.end())){
                if(--um[s[r]] == 0){
                    nonzero--;
                } 
            }  
            cout << " | " << s[l] << " : "<< s[r] << ", " << nonzero <<  " | ";
            
            while(nonzero == 0){
                if(res > (r - l + 1)){
                    res = r - l + 1;
                    strt = l;
                }

                    //res = "";
                    //for(char c : cur){
                       // res+=c;
                    //}
                //}
                   char left_char = s[l];
                if (um.count(left_char)) {
                    um[left_char]++;
                    if (um[left_char] > 0) nonzero++;
                }
                l++;
            }    
        }
         return (res == INT_MAX) ? "" : s.substr(strt, res);
    }
};
