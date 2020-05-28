/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    let m = word1.length;
    let n = word2.length;
    if (m === 0) return n;
    if (n === 0) return m;

    let dp = [...Array(m + 1)].map(x => Array(n + 1).fill(0));

    function dfs(word1, word2, i, j, dp) {
        if (dp[i][j] !== 0)
            return dp[i][j];
        if (i === 0)
            dp[0][j] = j;
        else if (j === 0)
            dp[i][0] = i;
        else if (word1[i - 1] === word2[j - 1])
            dp[i][j] = dfs(word1, word2, i - 1, j - 1, dp)
        else {
            dp[i][j] = 1 + Math.min(dfs(word1, word2, i - 1, j - 1, dp),
                dfs(word1, word2, i, j - 1, dp),
                dfs(word1, word2, i - 1, j, dp))
        }
        return dp[i][j];
    }
    return dfs(word1, word2, m, n, dp);
};