class KthLargest {
public:
    vector<int> res; 
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        res = nums;
        sort(res.begin() , res.end());
    }
    
    int add(int val) {
        res.push_back(val);
        sort(res.begin() , res.end());
        return res[res.size() - k];
    }
};
