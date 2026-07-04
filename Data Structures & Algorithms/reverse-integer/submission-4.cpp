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
        while(res[res.size() - 1] == '0'){
            res = res.substr(0, res.size() - 1);
        } 
        cout << s << "\n";
        cout << res << "\n";
        cout << i;
        return s == res ? i : 0;
    }
};
