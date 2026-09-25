class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(128, -1);
        int left = 0, best = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (last[c] >= left) left = last[c] + 1;
            last[c] = right;
            best = max(best, right - left + 1);
        }
        return best;
    }
};
