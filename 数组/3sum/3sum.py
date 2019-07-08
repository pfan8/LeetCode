# 用map实现，遍历2个数，找-i-j是否在map中
# 时间复杂度 O(n^2)
# 空间复杂度 O(n)
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []
        res = set()
        nums.sort()
        for i,v in enumerate(nums[:-2]):
            # trick：相同的值只遍历1次
            if i >= 1 and v == nums[i-1]:
                continue
            d = {} # 查看是否包含第三个数
            for x in nums[i+1:]:
                if x not in d:
                    d[-v-x] = 1
                else:
                    res.add((v,-v-x,x))
        return list(res)
                