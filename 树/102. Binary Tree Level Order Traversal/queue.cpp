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
    vector<vector<int>> levelOrder(TreeNode* root) {
        /*
            queue实现，当queue不为空时，不断循环添加子节点
            用int记录每一层的节点数量，当一层节点遍历完，就添加一个vector到res
            时间复杂度：O(n)
            空间复杂度：O(n)
        */
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> v;
        queue<TreeNode*> q;
        TreeNode* cur = root;
        q.push(cur);
        int layer_count = 0;
        int count = 1;
        while(!q.empty()) {
            if(!count) {
                count = layer_count;
                layer_count = 0;
                res.push_back(v);
                v.clear();
            }
            cur = q.front();
            v.push_back(cur->val);
            q.pop();
            count--;
            if(cur->left) {
                q.push(cur->left);
                layer_count++;
            }
            if(cur->right) {
                q.push(cur->right);
                layer_count++;
            }
        }
        if(v.size()) res.push_back(v);
        return res;
    }
};