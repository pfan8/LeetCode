class Solution {
/**
 *  i&(i-1) 去掉i的2进制中最后一位1
 *  因为去掉最后一位1的count肯定已经计算过了，类似于DP，因此count+1即可
 *  时间复杂度：O(n)
 *  空间复杂度：O(n)
 */
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for(int i = 1; i <= num; i++) {
            res[i] = res[i&(i-1)]+1;
        }
        return res;
    }
};