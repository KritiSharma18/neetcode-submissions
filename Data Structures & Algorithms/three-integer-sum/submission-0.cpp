class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] > 0) break;
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                long long sum = (long long)nums[i] + nums[lo] + nums[hi];
                if (sum < 0) {
                    lo++;
                } else if (sum > 0) {
                    hi--;
                } else {
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    lo++; hi--;
                    while (lo < hi && nums[lo] == nums[lo-1]) lo++;
                    while (lo < hi && nums[hi] == nums[hi+1]) hi--;
                }
            }
        }
        return res;
    }
};
