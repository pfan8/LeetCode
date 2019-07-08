class Solution:
    def findMin(self, nums: List[int]) -> int:
        left,right = 0,len(nums)-1
        if nums[right] >= nums[left]:
            return nums[left]
        while right >= left:
            mid = int((right+left)/2)
            if nums[mid] > nums[mid+1]:
                return nums[mid+1]
            if nums[mid-1] > nums[mid]:
                return nums[mid]
            if nums[mid] > nums[left]:
                left = mid
            else:
                right = mid