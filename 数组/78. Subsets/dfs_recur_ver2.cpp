class Solution {
/**
 *  递归实现，因为循环次数是动态的，没办法写在一个函数里
 *  时间复杂度：O(n^2)
 *  空间复杂度：O(n^2)
 */
private:
    void getSub(vector<int>& nums, int cur, const int& size, vector<vector<int>> &res,vector<int> &temp)
    {
        res.push_back(temp);
        
        for (int i = cur; i < size; i++) 
        {
            temp.push_back(nums[i]);
            getSub(nums, i+1, size, res, temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        auto size = nums.size();
        getSub(nums, 0, size, res, temp);
        return res;
    }
};