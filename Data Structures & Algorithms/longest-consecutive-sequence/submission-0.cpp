class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int longest = 0;

        for (int n : set) {
            if (set.find(n - 1) == set.end()) { // start of a sequence
                int length = 1;
                int curr = n;
                while (set.find(curr + 1) != set.end()) {
                    curr++;
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
