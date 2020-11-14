/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    let start = 0,
        end = nums.length - 1,
        cur = start;
    while (cur <= end) {
        if (nums[cur] === 0) {
            if (cur === start) {
                start++;
                cur++;
            } else {
                [nums[start], nums[cur]] = [nums[cur], nums[start]];
                start++;
            }
        } else if (nums[cur] === 2) {
            [nums[end], nums[cur]] = [nums[cur], nums[end]];
            end--;
        } else {
            cur++;
        }
    }
};