# 1. 遍历value，添加到list中
# 2. 对list排序
# 3. 再遍历修改原链表中的val
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        values = []
        cur = head
        while cur:
            values.append(cur.val)
            cur = cur.next
        cur = head
        values = sorted(values)
        for val in values:
            cur.val = val
            cur = cur.next
        return head