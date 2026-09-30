class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) return mid;

            // Left half [l..mid] is sorted
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid])
                    r = mid - 1;   // target is in left half
                else
                    l = mid + 1;   // go right
            }
            // Right half [mid..r] is sorted
            else {
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;   // target is in right half
                else
                    r = mid - 1;   // go left
            }
        }
        return -1;
    }
};
