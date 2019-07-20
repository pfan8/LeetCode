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
private:
    bool isValidBST(TreeNode* root, TreeNode* lower, TreeNode* upper) {
        if(!root) return true;
        if(lower && root->val <= lower->val) return false;
        if(upper && root->val >= upper->val) return false;
        
        if(!(isValidBST(root->left, lower, root))) return false;
        if(!(isValidBST(root->right, root, upper))) return false;
        
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
};