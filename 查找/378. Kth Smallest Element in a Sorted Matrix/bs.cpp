class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // 二分查找，每次统计个数，并和k比较
        // 时间复杂度：O(nlogn)，统计耗时O(n)，查找O(logn)
        // 空间复杂度：O(1)
        int n = matrix.size();
        if(n==1) return matrix[0][0];
        int lo = matrix[0][0];
        int hi = matrix[n-1][n-1];
        int mid;
        int row, col;
        int cnt;
        while(lo < hi) {
            mid = lo + (hi-lo)/2;
            cnt = 0;
            for(row=0,col=n-1; row < n; row++) {
                while(col>=0 && mid<matrix[row][col]) col--;
                cnt += col+1;
            }
            if(cnt < k) lo = mid+1;
            else hi = mid;
        }
        return lo;
    }
};