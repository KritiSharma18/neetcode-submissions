class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always binary search on the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int half = (m + n + 1) / 2;   // size of the left half
        int lo = 0, hi = m;

        while (lo <= hi) {
            int i = (lo + hi) / 2;    // elements taken from nums1
            int j = half - i;         // elements taken from nums2

            int Aleft  = (i == 0) ? INT_MIN : nums1[i - 1];
            int Aright = (i == m) ? INT_MAX : nums1[i];
            int Bleft  = (j == 0) ? INT_MIN : nums2[j - 1];
            int Bright = (j == n) ? INT_MAX : nums2[j];

            if (Aleft <= Bright && Bleft <= Aright) {
                // Correct partition found
                if ((m + n) % 2 == 1)
                    return max(Aleft, Bleft);
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            }
            else if (Aleft > Bright) {
                hi = i - 1;   // took too many from nums1
            }
            else {
                lo = i + 1;   // took too few from nums1
            }
        }
        return 0.0; // never reached
    }
};
