/* 快慢指针
 * 时间复杂度 O(n)
 * 空间复杂度 O(1)
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = nums[0];
        i = nums[i];
        int j = nums[0];
        while(i != j) {
            i = nums[i];
            i = nums[i];
            j = nums[j];
        }
        i = 0;
        while(i != j) {
            i = nums[i];
            j = nums[j];
        }
        return i;
    }
};