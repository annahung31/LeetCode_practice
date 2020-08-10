class Solution(object):
    def findKthLargest(self, nums, k):
        """
        O(NlogN)
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        length = len(nums)
        
        return nums[length-k]