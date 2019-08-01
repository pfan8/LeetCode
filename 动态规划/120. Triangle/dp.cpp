class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        // 时间复杂度：O(n)
        // 空间复杂度：O(n)，只保存最后一层，n/2
        int size = tri.size();
        if(!size) return 0;
        int dp[size] = {0};
        int tmp,tmp2; // 保存临时值，减少dp空间
        for(int i = 0; i < size; i++) {
            for(int j = 0; j <= i; j++) {
                if(j==0) {
                    tmp = dp[0];
                    dp[0] += tri[i][0];
                } else if(j==i) {
                    dp[i] = tmp + tri[i][i];
                } else {
                    tmp2 = min(tri[i][j]+tmp, tri[i][j]+dp[j]);
                    tmp = dp[j];
                    dp[j] = tmp2;
                }
            }
        }
        int min_val = INT_MAX;
        for(auto v: dp) {
            min_val = min(min_val, v);
        }
        return min_val;
    }
};