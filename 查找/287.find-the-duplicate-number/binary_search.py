class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        start,end = 1,len(nums)-1
        n = len(nums)-1
        while start <= end:
            mid = (start+end)//2
            lessThan,greaterThan = 0,0
            for number in nums:
                if number < mid:
                    lessThan += 1
                if number > mid:
                    greaterThan += 1
            if lessThan > mid - 1:
                end = mid - 1
            elif greaterThan > n - mid:
                start = mid + 1
            else:
                return mid
        return -1