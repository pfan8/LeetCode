// 最小堆实现，堆大小为k，如果比top元素大，则入堆，结果只需要返回top即可
// 时间复杂度O(n)：在堆大小小于k时，插入时间小于logk，但考虑增长性，假设全部插入操作均需要logk，时间复杂度为nlogk。认为k是常数，因此为O(n)
// 空间复杂度O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i : nums) {
            if(q.size() < k) {
                q.push(i);
            } else if(i > q.top()) {
                q.pop();
                q.push(i);
            }
        }
        return q.top();
    }
};