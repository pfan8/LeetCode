/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
/*
    用归并排序实现常数内存的排序，
    通过getMid和mergeSortList处理子生成子链表
    时间复杂度：O(nlogn)
    空间复杂度：O(1)
*/
private:
    ListNode* merge2L(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = (!l1 )? l2 : l1;
        return head->next;
    }
    
    ListNode* getMid(ListNode* front, ListNode* back) {
        if(front == back) return front;
        ListNode* slow = front;
        ListNode* fast = front;
        while(slow && fast && fast->next && fast->next->next ) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* mergeSortList(ListNode* head, ListNode* tail) {
        if(head == tail) return head;
        ListNode* mid = getMid(head, tail);
        ListNode* sortedPost = mergeSortList(mid->next, tail);
        mid->next = NULL;
        ListNode* sortedPre = mergeSortList(head, mid);
        
        return merge2L(sortedPre, sortedPost);
    }
    
    
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* tail = head;
        while(tail->next) {
            tail = tail->next;
        }
        return mergeSortList(head, tail);
    }
};