class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0 ; i < 31 ; i++){
            if(n % 2 == 1){
                res += 1;
            }
            res <<= 1;
            n >>= 1;
        }
     
        bitset<32> a(res);
    

        return n == 1 ? res + 1 : res;
    }
};
