class Solution {
private:
    int bst(vector<int>&v, int&val){
        int right = v.size(); 
        int left = 0; 
        while(right > left){
            int mid = (right+left)/2; 
            if(v[mid] == val)
                return mid;
            if(v[mid] > val)
                right = mid; 
            else
                left = mid+1;
        }
        return right; 
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
            动态规划+二分法：用一个数组保存当前最长子序列或分支，如果新的元素比某个元素小，则覆盖该元素
            时间复杂度 O(nlogn)
            空间复杂度 O(n)
        */
        vector<int> res;
        for(auto num: nums) {
            int i = bst(res, num);
            if(i == res.size()) {
                res.push_back(num);
            } else {
                res[i] = num;
            }
        }
        return res.size();
    }
};