/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalSquare = function(matrix) {
    rown = matrix.length;
    if (!rown) return 0;
    coln = matrix[0].length;
    if (!coln) return 0;

    let dp = new Array(rown)
    for (let i = 0; i < rown; i++) {
        dp[i] = new Array(coln);
    }
    let ans = 0;
    for (let i = 0; i < rown; i++) {
        dp[i][coln - 1] = matrix[i][coln - 1] === "0" ? 0 : 1;
        ans = dp[i][coln - 1] > ans ? dp[i][coln - 1] : ans;
    }
    for (let j = 0; j < coln; j++) {
        dp[rown - 1][j] = matrix[rown - 1][j] === "0" ? 0 : 1;
        ans = dp[rown - 1][j] > ans ? dp[rown - 1][j] : ans;
    }
    for (let i = rown - 2; i >= 0; i--) {
        for (let j = coln - 2; j >= 0; j--) {
            if (matrix[i][j] === "0") {
                dp[i][j] = 0;
            } else {
                let tmp = dp[i + 1][j] > dp[i][j + 1] ? dp[i][j + 1] : dp[i + 1][j];
                dp[i][j] = tmp;
                if (matrix[i + tmp][j + tmp] === '1') dp[i][j]++;
            }
            ans = dp[i][j] > ans ? dp[i][j] : ans;
        }
    }
    return ans ** 2;
};