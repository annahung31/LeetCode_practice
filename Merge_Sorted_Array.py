class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        Do not return anything, modify nums1 in-place instead.
        """
        
        if n == 0:
            nums1 = nums1
        if nums1[m-1] <= nums2[0]:
            
            for i in range(n):
                nums1[m+i] = nums2[i]
                
        elif nums1[0] >= nums2[-1]:
            
            for i in range(m):
                nums1[i] = nums1[n+i]
        else:
            ans = [None]*len(nums1)
            i = 0
            j = 0
            k = 0
            
            while i < m and j < n:
                if nums1[i] <= nums2[j]:
                    print("take 1: ", nums1[i])
                    ans[k] = nums1[i]
                    i += 1
                else:
                    print("take 2: ", nums2[j])
                    ans[k] = nums2[j]
                    j += 1
                k += 1

        nums1 = ans

if __name__ == "__main__":
    solve = Solution()
    nums1 = [1,2,3,0,0,0]
    m = 3
    nums2 = [2,5,6]
    n = 3
    solve.merge(nums1, m, nums2, n)
    print(nums1)

