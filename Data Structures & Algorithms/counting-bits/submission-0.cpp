class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        res[0]= 0;
        int curr = 0;
        for(int i = 1 ; i <= n ; i++){
            if(log(i) / log(2) == (int)(log(i) / log(2))){
                curr = i;
                res[i] = 1;
            }
            else{
                res[i] = 1 + res[i - curr];
            }
        }
        return res;
    }
};
