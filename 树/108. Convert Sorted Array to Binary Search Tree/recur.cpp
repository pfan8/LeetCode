/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
/*
    时间复杂度：O(logn)，递归二分
    空间复杂度：O(logn)，递归开销
*/
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if(start == end)
            return new TreeNode(nums[start]);
        int length = start + end;
        int mid = int(length/2);
        if(length % 2) mid++;
        TreeNode* res = new TreeNode(nums[mid]);
        if(mid-1 >= start)
            res->left = sortedArrayToBST(nums, start, mid-1);
        if(mid+1 <= end)
            res->right = sortedArrayToBST(nums, mid+1, end);
        return res;
    }
        
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size()) return NULL;
        int start = 0;
        int end = nums.size()-1;
        return sortedArrayToBST(nums, start, end);
    }
};