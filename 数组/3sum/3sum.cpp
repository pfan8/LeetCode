/* 思路2：用2个指针，第一个数遍历nums[:-2]，j指向i+1，k指向末尾
 *       如果nums[i] + nums[j] + nums[k] < 0，则j需要向后移动，同时判断重复
 *       如果nums[i] + nums[j] + nums[k] > 0，则k需要向前移动，同时判断重复
 *       如果满足，添加结果，并j,k同时移动一步
 *       当j >= k,退出循环
 * 时间复杂度 O(n^2)
 * 空间复杂度 O(n)
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size()-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1,k=nums.size()-1; j < k; ) {
                if(j > i+1 && nums[j] == nums[j-1]) {
                    j++;
                } else if(k < nums.size()-1 && nums[k] == nums[k+1]) {
                    k--;
                } else {
                    if(nums[i] + nums[j] + nums[k] > 0) k--;
                    else if(nums[i] + nums[j] + nums[k] < 0) j++;
                    else {
                        res.push_back({nums[i],nums[j],nums[k]});
                        j++;
                        k--;
                    }
                }
            }
        }
        return res;
    }
};