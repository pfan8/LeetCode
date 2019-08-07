class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        // 动规：dp[i,k]表示在i之后的位置分为至多k份的最佳选择，j表示分割位置
        // 则 dp[i,k] = max{dp[i,0], Mean(i,j)+dp[j,k-1]}
        // 时间复杂度：O(k*N*N)
        // 空间复杂度：O(N)，参考背包问题，复用空间
        int N = A.size();
        double P[N+1] = {0};
        for(int i = 0; i < N; i++) P[i+1] = P[i] + A[i];
        
        double dp[N] = {0};
        for(int i = 0; i < N; i++) dp[i] = (P[N]-P[i])/(N-i);
        for(int k = 1; k < K; k++) {
            for(int i = 0; i < N; i++) {
                for(int j = i+1; j < N; j++) {
                    dp[i] = max(dp[i], (P[j]-P[i])/(j-i) + dp[j]);
                }
            }
        }
        return dp[0];
    }
};