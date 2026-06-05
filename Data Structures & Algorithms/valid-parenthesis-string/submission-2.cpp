class Solution {
public:
    bool checkValidString(string str) {
        int lmin = 0, lmax = 0;
        for(auto& c : str){
            if(c == '('){
                lmin++;
                lmax++;
            }
            else if(c == '*'){
                lmin--;
                lmax++;
            }
            else{
                lmin--;
                lmax--;
            }

            if(lmin < 0) lmin = 0;
            if(lmax < 0) return false;
        }

        return lmin == 0;
    }
};
