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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        /*
            一次遍历，依次翻转
            时间复杂度：O(n)
            空间复杂度：O(1)
        */
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prem, *posm, *pre, *t;
        head = &dummy;
        for(int i = 0; i <= n; i++) {
            t = head->next;
            if( i == m - 1 ) {
                prem = head;
                posm = t;
            } else if( i > m ) {
                head->next = pre;
            }
            pre = head;
            head = t;
        }
        prem->next = pre;
        posm->next = head;
        return dummy.next;
    }
};