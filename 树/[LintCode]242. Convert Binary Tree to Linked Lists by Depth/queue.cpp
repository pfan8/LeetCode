/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        // Write your code here
        // 时间复杂度：O(n)
        // 空间复杂度：O(n),res保存n个节点
        vector<ListNode*> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        int pre_lc = 1;
        int lc = 0;
        TreeNode* tnode;
        ListNode* lnode = NULL;
        ListNode* head;
        while(!q.empty()) {
            tnode = q.front();
            if(!lnode) {
                lnode = new ListNode(tnode->val);
                head = lnode;
            } else {
                lnode->next = new ListNode(tnode->val);
                lnode = lnode->next;
            }
            q.pop();
            if(tnode->left) {
                q.push(tnode->left);
                lc++;
            }
            if(tnode->right) {
                q.push(tnode->right);
                lc++;
            }
            
            pre_lc--;
            if(!pre_lc) {
                pre_lc = lc;
                lc = 0;
                res.push_back(head);
                lnode = NULL;
            }
        }
        return res;
    }
};