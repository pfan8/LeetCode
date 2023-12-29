/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  // d[i][0] = max(d[i-1][0], d[i-1][1] + price[i])
  // d[i][1] = max(d[i-1][1], d[i-2][0] - price[i])
  if (prices.length < 2) return 0;
  let dp = [...Array(prices.length)].map((x) => Array(2).fill(0));
  dp[0][0] = 0;
  dp[0][1] = -prices[0];
  dp[1][0] = Math.max(0, dp[0][1] + prices[1]);
  dp[1][1] = Math.max(dp[0][1], -prices[1]);

  for (let i = 2; i < prices.length; i += 1) {
    dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
    dp[i][1] = Math.max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
  }

  return Math.max(dp[prices.length - 1][0], dp[prices.length - 2][0]);
};
