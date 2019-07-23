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
 *  用stack实现DFS
 *  时间复杂度：O(n)
 *  空间复杂度：O(n)
 */
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> v;
        
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = cur;
        st.push(root);
        v.push_back(root->val);
        int curLen = root->val;
        while(!st.empty()) {
            cur = st.top();
            if(!(cur->left || cur->right)) {
                if(curLen == sum) res.push_back(v);
                st.pop();
                v.pop_back();
                curLen -= cur->val;
                pre = cur;
            } else if (pre == cur->right
                || (pre==cur->left && !cur->right)) {
                st.pop();
                v.pop_back();
                curLen -= cur->val;
                pre = cur;
            } else if (cur->right
                       && (!cur->left || pre==cur->left)) {
                st.push(cur->right);
                v.push_back(cur->right->val);
                curLen += cur->right->val;
            } else {
                st.push(cur->left);
                v.push_back(cur->left->val);
                curLen += cur->left->val;
            }
        }
        return res;
    }
};