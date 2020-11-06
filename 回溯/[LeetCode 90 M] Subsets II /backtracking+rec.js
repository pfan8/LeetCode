/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function (nums) {
  // get rid of the duplicate by sorting
  // check the duplicate one
  nums.sort((a, b) => a - b);
  const res = [[]];
  rec(0, []);
  return res;

  function rec(idx, temp) {
    for (let i = idx; i < nums.length; i++) {
      if (i > idx && nums[i] === nums[i - 1]) continue;
      temp.push(nums[i]);
      res.push(temp.slice());
      rec(i + 1, temp);
      temp.pop();
    }
  }
};
