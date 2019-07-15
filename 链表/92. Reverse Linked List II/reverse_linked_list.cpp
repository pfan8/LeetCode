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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
            k_prev_node存储要删除节点的前一个节点
            如果k_prev_node为NULL，删除头节点
            时间复杂度：O(n)
            空间复杂度：O(1)
        */
        ListNode* k_prev_node = NULL;
        ListNode* t = head;
        while(t->next) {
            if(n > 1)
                n--;
            else if(!k_prev_node) 
                k_prev_node = head;
            else 
                k_prev_node = k_prev_node->next;
            t = t->next;
        }
        if(!k_prev_node)
            head = head->next;
        else if(!k_prev_node->next)
            k_prev_node->next = NULL;
        else
            k_prev_node->next = k_prev_node->next->next;
        return head;
    }
};