class Solution {
public:

    int hours_with_e (vector<int>& piles, int e){
        int res = 0;
        for(int i : piles){
            res += (i + e - 1) / e;
        }
        return res;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int mid = 0;
        int hours = 0;
        while(l < r){
            mid = l + ((r - l) / 2);
            //cout << mid << " || ";
            hours = hours_with_e(piles, mid);
            //cout << "time: " << hours << " speed: " << mid << "| ";
            if(hours > h){
                l = mid + 1;
            } else{
                r = mid;
            }
        }
       
    
        return l + ((r - l) / 2);;
    }
};
