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
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        else if(!s || !t) return false;
        if(s->val != t->val) return false;
        return isSameTree(s->left, t->left) && isSameTree(s->right,t->right);
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s || !t) return false;
        if(isSameTree(s,t))
            return true;
        // s和t不相等，判断s的子树是否包含t
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
};