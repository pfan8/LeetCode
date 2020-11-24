/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var wiggleSort = function (nums, l = (nums.length + 1) >>> 1, r = nums.length) {
  nums
    .slice()
    .sort((a, b) => a - b)
    .forEach((_, i, a) => (nums[i] = i & 1 ? a[--r] : a[--l]));
};
