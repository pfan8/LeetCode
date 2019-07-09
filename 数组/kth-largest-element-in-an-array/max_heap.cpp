/*
    最大堆实现：元素全部入堆，然后pop k-1次，再返回front即可
    时间复杂度：O(n)：构建堆需要O(n)（详细的推算可以在网上查到），pop k次，因此是O(n+k)，认为k是常数，因此为O(n)
    空间复杂度：O(n)
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        while(k > 1) {
            k--;
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return nums.front();
    }
};