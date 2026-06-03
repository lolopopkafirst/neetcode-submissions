class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int filled = 0;
        int total = 0;
        int curr = 0;
        for(int i = 0 ; i < gas.size() ; i++){
            filled += gas[i];
            total += gas[i] - cost[i];
            filled = filled - cost[i];
            if(filled < 0){
                curr = i + 1;
                filled = 0;
            }
            
        }
        return total < 0 ? -1 : curr;
    }
};
