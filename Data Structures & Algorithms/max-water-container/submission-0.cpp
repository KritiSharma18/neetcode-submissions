class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1, best = 0;
        while (l < r) {
            best = max(best, min(heights[l], heights[r]) * (r - l));
            if (heights[l] < heights[r]) l++;
            else r--;
        }
        return best;
    }
};
