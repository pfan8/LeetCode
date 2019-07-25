/* 双指针：二分查找
*  时间复杂度：O(logn)
*  空间复杂度：O(1)
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        if(nums[right] >= nums[left]) return nums[left];
        while(left <= right) {
            int mid = (left+right) / 2;
            if(nums[mid] > nums[mid+1])
                return nums[mid+1];
            if(nums[mid-1] > nums[mid])
                return nums[mid];
            if(nums[mid] > nums[left])
                left = mid+1;
            else
                right = mid-1;
        }
        return -1;
    }
};