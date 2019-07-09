class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        minh = []
        for item in nums:
            heapq.heappush(minh, item)
            if len(minh) > k:
                heapq.heappop(minh)
        return heapq.heappop(minh)