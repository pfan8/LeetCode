class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        # * merge sort constant space (bottom up)

        cnt = 0
        node = head
        while node is not None:
            node = node.next
            cnt += 1
        
        if cnt < 2:
            return head
        
        dummy = ListNode(-1)
        dummy.next = head

        merge_size = 1
        # merging all sublists with size <merge_size>
        # this loop will go on for log n times
        while merge_size < cnt:
            pre = dummy
            end = None
            i = 0
            # this loop takes O(n) time
            while cnt - i > merge_size:
                # find two sublists
                list0 = pre.next
                node = pre

                for _ in range(merge_size):
                    node = node.next
                
                i += merge_size
                
                # mark the break point
                mid = node
                
                for _ in range(min(merge_size, cnt - i)):
                    node = node.next

                i += min(merge_size, cnt - i)
                
                # break up the sublist from the nodes after it
                end = None
                if node is not None:
                    end = node.next
                    node.next = None
                
                # break the sublist into two parts
                list1 = mid.next
                mid.next = None

                # break the sublist from the nodes before it (optional)
                pre.next = None

                # merge the two sublists (and concatenate the new sublist to the nodes before)
                # the following steps take linear time because we are essentially concatenating nodes to ''pre''
                while list0 is not None and list1 is not None:
                    if list0.val < list1.val:
                        pre.next = list0
                        list0 = list0.next
                    else:
                        pre.next = list1
                        list1 = list1.next
                    
                    pre = pre.next
                
                pre.next = list0 if list0 is not None else list1
                while pre.next is not None:
                    pre = pre.next
                
                # concatenate these nodes to the rest
                pre.next = end

            merge_size <<= 1

        return dummy.next