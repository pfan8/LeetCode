class Solution {
public:
    int rob(vector<int>& nums) {
        // dp存储到i-1家和第i-2家能偷到的最多钱
        // 第i家只能加上第i-2家的钱，比较大小，更新
        // 时间复杂度：O(n)
        // 空间复杂度：O(n)
        auto size = nums.size();
        if(!size) return 0;
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[0], nums[1]);
        
        int dp[2] = {nums[0], max(nums[0], nums[1])};
        int tmp;
        for(int i = 2; i < size; i++) {
            tmp = max(dp[0]+nums[i], dp[1]);
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    }
};