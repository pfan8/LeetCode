/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function (nums) {
  let x1 = 0,
    x2 = 0;
  for (let x of nums) {
    [x2, x1] = [Math.max(x2, x1 + x), x2];
  }
  return x2;
};
