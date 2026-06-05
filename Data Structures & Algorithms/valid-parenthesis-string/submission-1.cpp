class Solution {
public:
    bool checkValidString(string str) {
        int l = 0;
        int lm = 0;
        int p = 0;
        for(auto& c : str){
            if(c == '('){
                l++;
                lm++;
            } 
            else if(c == ')'){
                l--;
                lm--;
            } 
            else{
                l--;
                lm++;
            } 
            if(l < 0) l = 0;
            if(lm < 0 )return false;
        }
        return l == 0;
    }
};
