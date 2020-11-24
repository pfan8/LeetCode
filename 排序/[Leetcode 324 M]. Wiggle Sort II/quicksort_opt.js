/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var wiggleSort = function (
  nums,
  s = 0,
  e = nums.length - 1,
  l = s,
  r = e,
  q = nums[s]
) {
  if (s > e) return;
  while (l < r) {
    while (l < r && nums[r] >= q) r--;
    while (l < r && nums[l] <= q) l++;
    swap(nums, l, r);
  }
  swap(nums, l, s);
  if (l > nums.length >>> 1) return wiggleSort(nums, s, l - 1);
  else if (l < nums.length >>> 1) return wiggleSort(nums, l + 1, e);
  for (var i = 0, q = nums[l], l = -1, r = nums.length; i < r; i++) {
    while (nums[i] > q && i < --r) swap(nums, i, r);
    nums[i] < q && i > ++l && swap(nums, i, l);
  }
  (l = (nums.length + 1) >>> 1), (r = nums.length), (q = nums.slice());
  nums.forEach((_, i) => (nums[i] = i & 1 ? q[--r] : q[--l]));
};
var swap = (a, i, j, t) => ((t = a[i]), (a[i] = a[j]), (a[j] = t));
