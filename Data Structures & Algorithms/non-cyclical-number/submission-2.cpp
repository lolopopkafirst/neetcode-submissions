class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> memo;
        return rek(n, memo);
    }
    bool rek(int n, unordered_set<int>& memo){
        if(n == 1) return true;
        int res = 0;
        while (n > 0){
            res += pow(n % 10, 2);
            n /= 10;
        }
        if(memo.find(res) != memo.end()) return false;
        memo.insert(res);
        return rek(res, memo);
    }
};
