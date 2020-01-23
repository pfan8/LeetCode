class Solution:
    def reorganizeString(self, S: str) -> str:
        count = [[0, i] for i in range(26)]
        for c in S:
            count[ord(c)-ord('a')][0] += 1
        
        count.sort(reverse=True, key=lambda a: a[0])
        
        n = len(S)
        for i in range(26):
            if count[i][0] > (n+1) // 2:
                return ""
            

        res = [''] * n
        k = 0
        for i in range(26):
            c = chr(count[i][1]+ord('a'))
            for j in range(count[i][0]):
                res[k] = c
                k += 2
                if k >= n:
                    k = 1
                    
        return ''.join(res)