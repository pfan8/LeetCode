class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return [-1,-1]
        # 非递归
        res = [-1,-1]
        if nums[0] == target:
            res[0] = 0
        if nums[-1] == target:
            res[1] = len(nums)-1
        
        # 找到最小范围
        low = 0
        high = len(nums)-1
        while low <= high:
            mid = (low+high)//2
            if nums[mid] == target:
                break
            elif nums[mid] > target:
                high = mid-1
            else:
                low = mid+1
        if low > high:
            return [-1,-1]
        
        # 二分查找left和right
        if res[0] == -1:
            left_low = low
            left_high = mid
            while left_low <= left_high:
                left_mid = (left_low+left_high)//2
                if nums[left_mid] == target:
                    if nums[left_mid-1] != target:
                        res[0] = left_mid
                        break
                    left_high = left_mid-1
                else:
                    if nums[left_mid+1] == target:
                        res[0] = left_mid+1
                        break
                    left_low = left_mid+1
            
        if res[1] == -1:
            right_low = mid
            right_high = high
            while right_low <= right_high:
                right_mid = (right_low+right_high)//2
                if nums[right_mid] == target:
                    if nums[right_mid+1] != target:
                        res[1] = right_mid
                        break
                    right_low = right_mid+1
                else:
                    if nums[right_mid-1] == target:
                        res[1] = right_mid-1
                        break
                    right_high = right_mid-1
            
        return res
