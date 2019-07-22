class Solution {
/**
 *  DFS递归实现，因为循环次数是动态的，没办法写在一个函数里
 *  时间复杂度：O(n^2)
 *  空间复杂度：O(n^2)
 */
private:
    vector<vector<int>> res;
    void DFS(vector<int> nums, int idx, vector<int> v) {
        if(idx == nums.size()) {
            res.push_back(v);
        } else {
            // 不选当前数
            DFS(nums, idx+1, v);
            // 选择当前数
            v.push_back(nums[idx]);
            DFS(nums, idx+1, v);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> v;
        int idx = 0;
        DFS(nums, idx, v);
        return res;
    }
};