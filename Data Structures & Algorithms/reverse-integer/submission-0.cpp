class Solution {
public:
    int reverse(int x) {
        long i = 0;
        while(x != 0){
            i *= 10;
            i += x % 10;
            x /= 10;
        }
        return i > INT_MAX || i < INT_MIN ?  0 : i ;
    }
};
