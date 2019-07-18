/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* merge2L(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l1;
                l1 = cur->next->next;
            }
            cur = cur->next;
        }
        if(!l1) cur->next = l2;
        else cur->next = l1;
        return head->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
            分治：每两个list合并，再不断合并，直至只剩下一个list
            时间复杂度：O(Nlogk)
            空间复杂度：O(1)
        */
        int k = lists.size();
        if(!k) return NULL;
        int interval = 1;
        while(interval < k) {
            for(int i = 0; i < k-interval; i += interval*2) {
                lists[i] = merge2L(lists[i], lists[i+interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }
};