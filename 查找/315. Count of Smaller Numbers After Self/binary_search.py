# 时间复杂度 O(nlogn)
# 空间复杂度 O(n)
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        if not len(nums):
            return []
        arr = [nums[-1]]
        res = [0]
        for val in nums[-2::-1]:
            count = -1
            if len(arr) == 1:
                if val > arr[0]:
                    arr.insert(0, val)
                    count = 1
                else:
                    arr.append(val)
                    count = 0
            else:
                # 二分查找
                left,right = 0,len(arr)-1
                while count == -1:
                    mid = int((left+right)/2)
                    if val > arr[mid]:
                        if mid == 0:
                            count = len(arr)
                            arr.insert(0, val)
                        elif val <= arr[mid-1]:
                            count = len(arr)-mid
                            arr.insert(mid, val)
                        else:
                            right = mid
                    else:
                        if mid == len(arr)-1:
                            count = 0
                            arr.append(val)
                        if val > arr[mid+1]:
                            count = len(arr)-mid-1
                            arr.insert(mid+1, val)
                        else:
                            left = mid+1
            res.insert(0,count)
        return res
                    