class Solution {
/**
 *  DP：考虑第[i][j]个格子，其可能的路径数量由[i-1][j]和[i][j-1]相加可得
    （i-1和j-1大于0），同时memo只需要存一列或者一行
    更新的时候加上一行或者上一列的数量
    时间复杂度：O(m*n)
    空间复杂度：min(O(m),O(n)),取决于memo
 */
public:
    int uniquePaths(int m, int n) {
        if(m < n) {
            vector<int> memo(m);
            int prev = 1;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    memo[j] += prev;
                    prev = memo[j];
                }
                prev = 0;
            }
            return memo[m-1];
        } else {
            vector<int> memo(n);
            int prev = 1;
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    memo[j] += prev;
                    prev = memo[j];
                }
                prev = 0;
            }
            return memo[n-1];
        }
    }
};