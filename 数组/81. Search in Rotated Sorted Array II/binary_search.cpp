class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // 时间复杂度：平均O(logn)，最差O(n)，因为如果不知道翻转点在哪侧，则可能遍历全部元素
        // 空间复杂度：O(1)
        if(!nums.size()) return false;
        int left = 0, right = nums.size()-1, mid;
        while(left < right) {
            mid = (left+right)/2;
            if(nums[mid]==target) return true;
            if(nums[right] > nums[left]) {
                if(nums[mid] > target) right = mid;
                else left = mid+1;
            } else {
                if(nums[mid]==nums[left] && nums[mid]==nums[right]) {
                    //不知道翻转点在哪
                    for(int i = left; i <= right; i++) {
                        if(nums[i] == target) return true;
                    }
                    return false;
                } else if(nums[mid] >= nums[left]) {
                    // 翻转点在右侧
                    if(nums[mid] < target) left = mid+1;
                    else if(nums[left] > target) left = mid+1;
                    else right = mid;
                } else {
                    // 翻转点在左侧
                    if(nums[mid] > target) right = mid;
                    else if(nums[right] < target) right = mid;
                    else left = mid+1;
                }
            }
        }
        return nums[left]==target;
    }
};