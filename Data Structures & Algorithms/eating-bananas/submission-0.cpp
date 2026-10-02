class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int k = low + (high - low) / 2;   // middle speed

            long long hours = 0;              // long long: the sum can exceed int
            for (int p : piles) {
                hours += (p + (long long)k - 1) / k;   // ceil(p / k)
            }

            if (hours <= h) {      // k works, so try a smaller speed
                ans = k;
                high = k - 1;
            } else {               // too slow, so speed up
                low = k + 1;
            }
        }
        return ans;
    }
};