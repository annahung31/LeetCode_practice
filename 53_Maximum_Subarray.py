class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) ==1:
            return nums[0]
        else:
            _sum = nums[0]
            ans = nums[0]
        
            for i in range(1,len(nums)):
                _sum = max(_sum + nums[i], nums[i])  #如果沒有變多，就重新開始計算
                if _sum > ans:
                    ans = _sum
        
            return ans
        