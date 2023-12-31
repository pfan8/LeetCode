// DFS 1176ms:  45.93% fast
// reference: https://leetcode.com/problems/target-sum/discuss/97371/Java-Short-DFS-Solution
let res = 0;
const findTargetSumWays = (nums, S) => {
  res = 0;
  helper(nums, 0, 0, S);
  return res;
};

const helper = (nums, idx, sum, S) => {
  let n = nums.length;
  if (idx == n) {
    if (sum == S) res++;
    return;
  }
  helper(nums, idx + 1, sum, S + nums[idx]);
  helper(nums, idx + 1, sum, S - nums[idx]);
};

// DP with Map 136ms:  84.39% fast
// reference: https://leetcode.com/problems/target-sum/discuss/97439/JavaPython-Easily-Understood
const findTargetSumWays = (nums, S) => {
  let dp = new Map();
  dp.set(0, 1);
  for (const x of nums) {
    let tmp = new Map();
    for (const y of dp.keys()) {
      tmp.set(y + x, getOrDefault(tmp, y + x, 0) + dp.get(y));
      tmp.set(y - x, getOrDefault(tmp, y - x, 0) + dp.get(y));
    }
    dp = tmp;
  }
  return getOrDefault(dp, S, 0);
};

const getOrDefault = (map, k, v) => {
  if (!map.has(k)) {
    return v;
  }
  return map.get(k);
};

// DP with Subset Sum:  64ms 100.00% fast
// reference: https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C%2B%2B-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation
const findTargetSumWays = (nums, S) => {
  let sum = nums.reduce((acc, cur) => acc + cur);
  return sum < S || (sum + S) % 2 > 0 ? 0 : subsetsSum(nums, (sum + S) >> 1);
};

const subsetsSum = (nums, S) => {
  let dp = new Array(S + 1).fill(0);
  dp[0] = 1;
  for (const n of nums) {
    for (let i = S; i >= n; i--) {
      dp[i] += dp[i - n];
    }
  }
  return dp[S];
};
