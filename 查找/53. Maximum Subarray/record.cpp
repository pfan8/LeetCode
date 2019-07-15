/*
 * 时间复杂度 O(n)
 * 空间复杂度 O(1)
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum = 0;
        int res = nums[0];
        for(int x: nums) {
            if(cursum < 0) cursum = 0;
            cursum += x;
            res = max(res, cursum);
        }
        return res;
    }
};