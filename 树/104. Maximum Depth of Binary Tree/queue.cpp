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
    int maxDepth(TreeNode* root) {
        /*
            Queue实现
            时间复杂度：O(n)
            空间复杂度：O(n)
        */
        if(!root) return 0;
        int max_depth = 1;
        int prev_lc = 0;
        int lc = 1;
        queue<TreeNode*> q;
        auto cur = root;
        q.push(cur);
        while(!q.empty()) {
            if(!lc) {
                if(!prev_lc)
                    break;
                max_depth++;
                lc = prev_lc;
                prev_lc = 0;
            }
            cur = q.front();
            q.pop();
            lc--;
            if(cur->left) {
                q.push(cur->left);
                prev_lc++;
            }
            if(cur->right) {
                q.push(cur->right);
                prev_lc++;
            }
        }
        return max_depth;
    }
};