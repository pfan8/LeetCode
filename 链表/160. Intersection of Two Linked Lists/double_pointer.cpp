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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
            双指针：一个指针遍历A->B，令一个指针遍历B->A,如果有交点，第一个相同的元素即为交点，否则遍历完则无交点
            时间复杂度：O(m+n)
            空间复杂度：O(1)
        */
        if(!headA || !headB) return NULL;
        ListNode* iter1 = headA;
        ListNode* iter2 = headB;
        int switch_count = 0;
        while(iter1 != iter2) {
            iter1 = iter1 ? iter1->next : headB;
            iter2 = iter2 ? iter2->next : headA;
        }
        return iter1;
    }
};