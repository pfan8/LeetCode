class Solution {
private:
    void quicksort(vector<int>& nums, int left, int right) {
        if(right <= left) return;
        int begin = left;
        int end = right;
        int pivot = rand() % (right+1-left) + left;
        swap(nums[pivot], nums[right]);
        pivot = right--;
        while(right > left) {
            if(nums[left] <= nums[pivot]) {
                left++;
                continue;
            }
            if(nums[right] >= nums[pivot]) {
                right--;
                continue;
            }
            swap(nums[left++], nums[right]);
        }
        if(nums[left] < nums[pivot]) left++;
        swap(nums[pivot], nums[left]);
        quicksort(nums, begin, left-1);
        quicksort(nums, left+1, end);
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;
        quicksort(nums, 0, nums.size()-1);
        for(int i = 0; i < nums.size()-2; i++) {
            if(i && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            while(k > j) {
                if(nums[i]+nums[j]+nums[k] < 0) {
                    j++;
                    continue;
                }
                if(nums[i]+nums[j]+nums[k] > 0) {
                    k--;
                    continue;
                }
                res.push_back({nums[i], nums[j], nums[k]});
                while(nums[j]==nums[++j] && k > j) continue;
                while(nums[k]==nums[--k] && k > j) continue;
            }
        }
        return res;
    }
};