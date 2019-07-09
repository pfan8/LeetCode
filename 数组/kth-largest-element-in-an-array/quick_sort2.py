class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        i0 = i = 0
        j0 = j = len(nums)-1
        while True:
            pivot = random.randint(i,j)
            nums[pivot],nums[j] = nums[j],nums[pivot]
            pivot = j
            while i < j:
                if nums[j] >= nums[pivot]:
                    j -= 1
                    continue
                if nums[i] <= nums[pivot]:
                    i += 1
                    continue
                nums[i],nums[j] = nums[j],nums[i]
                i += 1
                j -= 1
            # pivot放中间
            if nums[pivot] <= nums[j]:
                nums[pivot],nums[j] = nums[j],nums[pivot]
            else:
                nums[pivot],nums[j+1] = nums[j+1],nums[pivot]
                j += 1
            # 判断是否返回结果
            if j == len(nums)-k:
                return nums[j]
            elif j > len(nums)-k:
                i = i0
                j0 = j
            else:
                i = i0 = j+1
                j = j0
        return None                