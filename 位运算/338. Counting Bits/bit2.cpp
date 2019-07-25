class Solution {
/**
 *  i>>1 i除以2的数
 *  因为i>>1肯定比i小，所以其count肯定已经计算过了，类似于DP，因此count+(i&1)即可
 *  时间复杂度：O(n)
 *  空间复杂度：O(n)
 */
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for(int i = 1; i <= num; i++) {
            res[i] = res[i>>1]+(i&1);
        }
        return res;
    }
};