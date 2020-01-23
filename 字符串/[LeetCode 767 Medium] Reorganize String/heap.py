class Solution:
    def reorganizeString(self, S: str) -> str:
        # store the result as a list, then join at the end
        res = []
        
        # build a dictionary of character frequency
        char_counts = collections.Counter(S)
        
        # build a max-heap of tuples of character frequency, character
        max_heap = [(-count, char) for char, count in char_counts.items()]
        heapq.heapify(max_heap)
            
        # add the 2 most frequent characters to the result
        while len(max_heap) > 1:
            count_1, char_1 = heapq.heappop(max_heap)
            count_2, char_2 = heapq.heappop(max_heap)
            res.extend([char_1, char_2])
            # decrement the character counts and add them back to the max-heap
            if count_1 + 1:
                heapq.heappush(max_heap, (count_1 + 1, char_1))
            if count_2 + 1:
                heapq.heappush(max_heap, (count_2 + 1, char_2))
                
        if max_heap:
            count, char = heapq.heappop(max_heap)
            count = abs(count)
            # if the count is greater than 1, can't build an alternating string
            if count > 1:
                return ''
            # if there is a final character of count 1, add it to the heap
            elif count == 1:
                res.append(char)

        return ''.join(res)