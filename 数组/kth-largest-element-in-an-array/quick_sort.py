class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        pivot = i = 0
        j0 = j = len(nums)-1
        while True:
            while i < j:
                if nums[j] <= nums[pivot]:
                    j -= 1
                    continue
                if nums[i] >= nums[pivot]:
                    i += 1
                    continue
                nums[i],nums[j] = nums[j],nums[i]
                i += 1
                j -= 1
            # pivot放中间
            if nums[pivot] <= nums[j]:
                nums[pivot],nums[j] = nums[j],nums[pivot]
            else:
                nums[pivot],nums[j-1] = nums[j-1],nums[pivot]
                j -= 1
            # 判断是否返回结果
            if j == k-1:
                return nums[j]
            elif j > k-1:
                i = pivot
                j0 = j
            else:
                pivot = i = pivot+1
                j = j0
        return None                