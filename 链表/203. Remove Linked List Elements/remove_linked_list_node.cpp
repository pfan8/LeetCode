/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        /*
            时间复杂度：O(n)
            空间复杂度：O(1)
        */
        if(!head) return NULL;
        ListNode* prev = head;
        while(prev->next) {
            if(prev->next->val == val) {
                prev->next = prev->next->next;
            } else {
                prev = prev->next;
            }
        }
        if(head->val == val) head = head->next;
        return head;
    }
};