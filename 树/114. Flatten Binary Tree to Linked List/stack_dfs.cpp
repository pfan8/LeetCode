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
/**
 *  stack实现DFS，先压入右儿子，再压入左儿子
 *  时间复杂度：O(n)
 *  空间复杂度：O(n)
 */
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* cur = new TreeNode(-1);
        TreeNode* pre = cur;
        while (!st.empty()) {
            pre = cur;
            cur = st.top();
            st.pop();
            pre->left = NULL;
            pre->right = cur;
            if (cur->right) {
                st.push(cur->right);
            }
            if (cur->left) {
                st.push(cur->left);
            }
        }
    }
};