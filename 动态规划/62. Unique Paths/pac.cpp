class Solution {
/**
 *  排列组合： → 只能走m-1次， ↓ 只能走n-1次，其实就相当于将 → 插入m+n-2个格子中
                有几种组合
    注意要做double和round处理，否则会溢出或者结果不对
    时间复杂度：min(O(n),O(m))
 */
public:
    int uniquePaths(int m, int n) {
        if(n==1 || m==1) return 1;
        double res = 1;
        int count = min(m-1, n-1);
        for(int i = 0; i < count; i++) {
            res *= (m+n-2-i) / double(count-i);
        }
        return round(res);
    }
};