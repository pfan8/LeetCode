# 时间复杂度 O(nlogn)
# 空间复杂度 O(n)
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        arr,res = [],[]
        for x in nums[::-1]:
            idx = bisect.bisect_left(arr, x)
            res.append(idx)
            arr[idx:idx] = [x]
        return res[::-1]