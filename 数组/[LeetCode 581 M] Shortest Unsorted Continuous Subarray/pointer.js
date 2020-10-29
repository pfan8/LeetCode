/**
 * @param {number[]} nums
 * @return {number}
 */
var findUnsortedSubarray = function (nums) {
  let min = 1e5,
    max = -1e5;
  let flag = false;
  for (let i = 0; i < nums.length - 1; i += 1) {
    if (nums[i] > nums[i + 1]) {
      min = Math.min(nums[i + 1], min);
    }
  }
  for (let i = nums.length - 1; i > 0; i -= 1) {
    if (nums[i] < nums[i - 1]) {
      max = Math.max(nums[i - 1], max);
    }
  }

  let l = 0,
    r = nums.length - 1;

  for (; l < nums.length; l += 1) {
    if (min < nums[l]) {
      break;
    }
  }

  for (; r >= 0; r -= 1) {
    if (max > nums[r]) {
      break;
    }
  }

  return r > l ? r - l + 1 : 0;
};
