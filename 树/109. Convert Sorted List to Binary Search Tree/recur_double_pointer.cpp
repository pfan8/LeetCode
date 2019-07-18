/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
/*
    递归+快慢指针查找中点
    时间复杂度：O(nlogn)，快慢指针找中点需要遍历需要n，递归需要logn
    空间复杂度：O(logn)，递归开销 
*/
private:
    ListNode* getMid(ListNode* begin, ListNode* end) {
        if(begin == end) return begin;
        ListNode* slow = begin;
        ListNode* fast = slow->next;
        while(fast->next && fast->next->next) {
            if(fast==end || fast->next==end) break;
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    TreeNode* sortedListToBST(ListNode* start, ListNode* end) {
        ListNode* mid = getMid(start, end);
        TreeNode* tnode;
        if(mid != end) {
            tnode = new TreeNode(mid->next->val);
            tnode->left = sortedListToBST(start, mid);
            if(mid->next != end)
                tnode->right = sortedListToBST(mid->next->next, end);
        } else {
            tnode = new TreeNode(mid->val);
        }
        return tnode;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        ListNode* end = head;
        while(end->next) {
            end = end->next;
        }
        return sortedListToBST(head, end);
    }
};