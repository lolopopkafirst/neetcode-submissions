class Solution {
public:
    double myPow(double x, int n) {
        double step = x;
        if(n == 0) return 1;
        if(x == 1) return 1;
        if(x == 0) return 0;
        if(x == -1) return n % 2 == 0 ? 1 : -1;

        if(n > 0){
            
            for(int i = 1 ; i < n ; i++){
                x *= step;
            }   
        }
        else if(n < 0){
            if (-10000 > n) return 0;
            for(int i = 0 ; i >= n ; i--){
                x *= (double)1/step;
            }   
        }
    
       
        return x;
    }
};
