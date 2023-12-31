/**
 * @param {number} k
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (k, prices) {
  const len = prices.length;
  const remain = k;
  const dp = [...Array(len + 1)].map(() =>
    [...Array(remain + 1)].map(() => [...Array(2)].fill(0))
  );

  for (let i = 0; i <= remain; i++) {
    dp[0][i][1] = i === remain - 1 ? -prices[0] : -10e5;
  }

  for (let i = 0; i < len; i++) {
    // no remain count
    for (let j = remain - 1; j >= 0; j--) {
      dp[i + 1][j][0] = Math.max(dp[i][j][0], dp[i][j][1] + prices[i]);
      dp[i + 1][j][1] = Math.max(dp[i][j + 1][0] - prices[i], dp[i][j][1]);
    }
  }

  let ans = 0;
  for (let i = 0; i <= remain; i++) {
    ans = Math.max(ans, dp[len][i][0], dp[len][i][1]);
  }
  return ans;
};
