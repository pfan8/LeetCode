class Solution {
// 时间复杂度：O(n)
// 空间复杂度：O(n)
private:
    int rob(vector<int>& nums, int start, int end) {
        int size = end-start;
        int dp[2] = {nums[start], max(nums[start], nums[start+1])};
        int tmp;
        for(int i = start+2; i < end; i++) {
            tmp = max(dp[0]+nums[i], dp[1]);
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    }
public:
    int rob(vector<int>& nums) {
        auto size = nums.size();
        if(!size) return 0;
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[0], nums[1]);
        // convert to Houser Robber
        return max(rob(nums,0,size-1), rob(nums,1,size));
    }
};