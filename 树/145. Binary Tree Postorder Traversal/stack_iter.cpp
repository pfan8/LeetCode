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
    vector<int> postorderTraversal(TreeNode* root) {
        /*
            用stack实现，和中序遍历一样
            时间复杂度：O(n)
            空间复杂度：O(n)
        */
        vector<int> res;
        if(!root) return res;
        
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = cur;
        st.push(cur);
        while(!st.empty()) {
            if((pre == cur->right)
                || !(cur->right || cur->left)
                || (pre==cur->left && !cur->right)) {
                pre = cur;
                res.push_back(cur->val);
                st.pop();
                if(st.empty()) return res;
                cur = st.top();
            } else if(pre == cur->left || cur->left == NULL) {
                cur = cur->right;
                st.push(cur);
            } else {
                cur = cur->left;
                st.push(cur);
            }
        }
        return res;
    }
};