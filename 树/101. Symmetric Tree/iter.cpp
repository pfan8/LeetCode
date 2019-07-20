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
public:
    bool isSymmetric(TreeNode* root) {
        /*
            循环非递归，使用Queue辅助
            时间复杂度：O(n)
            空间复杂度：O(n)
        */
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        TreeNode* t1;
        TreeNode* t2;
        while(!q.empty()) {
            t1 = q.front();
            q.pop();
            t2 = q.front();
            q.pop();
            if(!t1 && !t2) continue;
            if(!t1 || !t2) return false;
            if(t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};