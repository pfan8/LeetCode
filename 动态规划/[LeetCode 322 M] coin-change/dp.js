/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function (coins, amount) {
  // dp[i] = min(dp[i-1, amount], dp[i-1, amount-coins[i]])
  const dp = [...Array(amount + 1)].fill(Infinity);
  dp[0] = 0;

  for (let i = 0; i < coins.length; i++) {
    for (let j = coins[i]; j <= amount; j++) {
      dp[j] = Math.min(dp[j], dp[j - coins[i]] + 1);
    }
  }
  return dp[amount] === Infinity ? -1 : dp[amount];
};
