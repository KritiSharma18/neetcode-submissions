class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curSum=0
        maxSub = nums[0]
        for num in nums:
            if curSum<0:
                curSum=0
            curSum += num
            maxSub = max(maxSub,curSum)
        return maxSub