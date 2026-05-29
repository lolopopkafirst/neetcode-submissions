class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 == 0){
            return (n2 & 1) == 0 ? ((double) nums2[(n2 / 2) - 1] + nums2[(n2 / 2)]) / 2 : nums2[(n2 / 2)];
        }
        else if(n2 == 0) {
            return (n1 & 1) == 0 ? ((double) nums1[(n1 / 2) - 1] + nums1[(n1 / 2)]) / 2 : nums1[(n1 / 2)];
        }
        int i = 0;
        int j = 0;

        while(i + j < (n1 + n2 - 1) / 2){
            if(nums1[i] > nums2[j]){
                j++;
            } else {
                i++;
            }
        }
        cout << nums1[i] << nums2[j];
        if(((n1 + n2) & 1) == 0) return (((double)nums1[i] + nums2[j]) / 2);
        return nums1[i] < nums2[j] ? nums1[i] : nums2[j];
        
    }
};
