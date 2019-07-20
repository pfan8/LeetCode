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
    int kthSmallest(TreeNode* root, int k) {
        /*
            和中序遍历类似，用stack循环实现，遍历完左子树count++
            当count等于k，返回结果
            时间复杂度：O(n)
            空间复杂度：O(n)
        */
        int count = 0;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* cur = root;
        TreeNode* pre = cur;
        while(count < k) {
            cur = st.top();
            if(!cur->left && !cur->right) {
                count++;
                pre = cur;
                st.pop();
            } else if(pre == cur->right) {
                pre = cur;
                st.pop();
            } else if(cur->left) {
                if(pre == cur->left) {
                    count++;
                    if(cur->right) {
                        st.push(cur->right);
                    } else {
                        pre = cur;
                        st.pop();
                    }
                } else {
                    st.push(cur->left);
                }
            } else {
                count++;
                st.push(cur->right);
            }
        }
        return cur->val;
    }
};