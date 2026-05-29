class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
            vector<pair<int, double>> res;
            for(int i = 0 ; i < position.size() ; i++){
                res.push_back({position[i] , ((double)(target - position[i]) /(speed[i]))});
            }
            int result = 0;
            int curr = 0;
            sort(res.begin(), res.end());
            int counter = 1;
            for(int i = res.size() - 2 ; i >= 0; i--){
                if(res[i].second <= res[i + 1].second){
                    res[i].second = res[i + 1].second;
                    continue;
                } 
                else{
                    counter++;
                }
            }
            return counter;
    }
};      


//
