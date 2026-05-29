class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {

        if (A.size() > B.size())
            swap(A, B);

        int m = A.size();
        int n = B.size();

        int total = m + n;
        int half = total / 2;

        int l = 0;
        int r = m;

        while (true) {

            int i = (l + r) / 2;
            int j = half - i;

            int Aleft  = (i > 0) ? A[i - 1] : INT_MIN;
            int Aright = (i < m) ? A[i] : INT_MAX;

            int Bleft  = (j > 0) ? B[j - 1] : INT_MIN;
            int Bright = (j < n) ? B[j] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {

                if (total % 2) {
                    return min(Aright, Bright);
                }

                return (max(Aleft, Bleft) +
                        min(Aright, Bright)) / 2.0;
            }

            else if (Aleft > Bright) {
                r = i - 1;
            }

            else {
                l = i + 1;
            }
        }
    }
};