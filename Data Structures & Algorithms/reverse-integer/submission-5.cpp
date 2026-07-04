class Solution {
public:
    int reverse(int x) {
        int temp = x;
        int i = 0;
        while(temp != 0){
            i *= 10;
            i += temp % 10;
            temp /= 10;
        }
        string s = to_string(abs(i));
        std::reverse(s.begin(), s.end());
        string res = to_string(abs(x));
        int index = 0;
        while(res[res.size() - 1 - index] == '0'){
            ++index;
        } 
        return s == res.substr(0, res.size() - index) ? i : 0;
    }
};
