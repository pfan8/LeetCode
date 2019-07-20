class Solution {
public:
    /**
     * @param n: An integer
     * @return: return a  integer as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        /*
            动态规划，并用3个指针记录，减少循环
            时间复杂度：O(n)
            空间复杂度：O(n)
        */
        int memo[n] = {0};
        int index2 = 0;
        int M2 = 0;
        int index3 = 0;
        int M3 = 0;
        int index5 = 0;
        int M5 = 0;
        memo[0] = 1;
        int threshold;
        for(int i = 1; i < n; i++) {
            threshold = memo[i-1];
            while(memo[index2]*2 <= threshold) {
                index2++;
            }
            M2 = memo[index2]*2;
            
            while(memo[index3]*3 <= threshold) {
                index3++;
            }
            M3 = memo[index3]*3;
            
            while(memo[index5]*5 <= threshold) {
                index5++;
            }
            M5 = memo[index5]*5;
            memo[i] = M2<M3 ? (M2<M5?M2:M5) : (M3<M5?M3:M5);
        }
        return memo[n-1];
    }
};