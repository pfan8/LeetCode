/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var findTargetSumWays = function (nums, target) {
  // const dfs = (idx, target) => {
  //     if(idx < 0) {
  //         return target === 0;
  //     }

  //     return dfs(idx-1, target-nums[idx]) + dfs(idx-1, target+nums[idx]);
  // }
  // return dfs(nums.length-1, target);

  /**
      p
      s-p
      p-(s-p) = t
      2p = t+s
      p = t+s / 2
   */
  const sum = nums.reduce((res, cur) => res + cur, 0);
  target += sum;
  if (target < 0 || target & 1) {
    return 0;
  }
  target >>= 1;
  // f[i+1][t] = f[i][t] + f[i][t - nums[i]]
  const dp = [...Array(target + 1)].fill(0);
  dp[0] = 1;
  for (let i = 0; i < nums.length; i++) {
    for (let j = target; j >= nums[i]; j--) {
      dp[j] = dp[j] + dp[j - nums[i]];
    }
  }
  return dp[target];
};
