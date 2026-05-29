class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
            vector<pair<int, double>> res;
            for(int i = 0 ; i < position.size() ; i++){
                res.push_back({position[i] , (static_cast<double> (target - position[i]) / static_cast<double> (speed[i]))});
            }
            int result = 0;
            int curr = 0;
            sort(res.begin(), res.end());
            for(const auto& [in, val] : res){
                cout << in;
            }
            int counter = 1;
            for(int i = res.size() - 2 ; i >= 0; i--){
                cout << " " << res[i].second << ", "<< res[i + 1].second;
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
