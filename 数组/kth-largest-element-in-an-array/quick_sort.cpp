/*
    快排思想：将比nums[pivot]大的元素放pivot左边，小的元素放右边
    则：
    1. pivot == k-1，即找到第k大的元素，返回
    2. pivot >  k-1，第k大的元素在pivot左边，继续在左边[i,pivot]快排查找
    3. pivot <  k-1，第k大的元素在pivot右边，继续在右边[pivot,j]快排查找
    时间复杂度：O(n)：最差情况k次均需要遍历所有值，即 n + (n-1) + (n-2) + ... + (n-k-1) = kn-k*k/2，认为k为常数，因此时间复杂度O(n)
    空间复杂度：O(1)
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 1) return nums[0];
        int pivot = 0;
        int i = pivot;
        int j0 = nums.size()-1;
        int j = j0;
        while(true) {
            while(i < j) {
                if(nums[j] <= nums[pivot]) {
                    j--;
                    continue;
                }
                if(nums[i] >= nums[pivot]) {
                    i++;
                    continue;
                }
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if(nums[pivot] <= nums[j]) {
                swap(nums[pivot], nums[j]);                
            } else {
                swap(nums[pivot], nums[--j]);
            }
            
            if(j == k-1) {
              return nums[j];
            } else if(j < k-1) {
                pivot = j+1;
                i = pivot;
                j = j0;
            } else {
                i = pivot;
                j0 = j;
            }
        }
    }
};