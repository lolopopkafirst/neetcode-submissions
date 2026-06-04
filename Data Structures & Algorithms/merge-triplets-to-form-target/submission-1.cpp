class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x = false, y = false, z = false;
        for(vector<int>& v : triplets){
            x |= v[0] == target[0] && v[1] <= target[1] && v[2] <= target[2];
            y |= v[0] <= target[0] && v[1] == target[1] && v[2] <= target[2];
            z |= v[0] <= target[0] && v[1] <= target[1] && v[2] == target[2];

            cout << z;
        }
        return x && y && z;
    }
};
