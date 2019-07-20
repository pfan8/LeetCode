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
    vector<int> inorderTraversal(TreeNode* root) {
        /*
            用stack和2个指针，实现中序遍历，当栈顶元素有左儿子，就入栈左儿子
            否则打印栈顶元素，并入栈右儿子，如果右儿子出栈，则父节点也出栈
            时间复杂度：O(n)
            空间复杂度：O(n)
        */
        vector<int> res;
        if(!root) return res;
        
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* cur = root;
        TreeNode* pre = cur;
        while(!st.empty()) {
            if(pre == cur->right) {
                pre = st.top();
                st.pop();
                if(st.empty()) return res;
                cur = st.top();
                continue;
            } else if(pre != cur->left) {
                while(cur->left) {
                    cur = cur->left;
                    st.push(cur);
                }
            }
            res.push_back(st.top()->val);
            if(cur->right) {
                cur = cur->right;
                st.push(cur);
            } else {
                pre = st.top();
                st.pop();
                if(st.empty()) return res;
                cur = st.top();
            }
        }
        return res;
    }
};