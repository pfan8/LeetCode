class Solution:
    def getpi(self, needle: str) -> list:
        pi = [0]*len(needle)
        p = 1
        while p < len(needle):
            # [0:p]前后缀最长公共元素长度作为填入值
            flag = False
            # range取值[a,b)
            for i in range(p,0,-1):
                if needle[:i] == needle[p-i+1:p+1]:
                    flag = True
                    pi[p] = i
                    break
            p += 1
        return pi
    
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        
        # KMV
        pi = self.getpi(needle)
        hi = ni = 0
        while ni < len(needle) and hi < len(haystack):
            if needle[ni] == haystack[hi]:
                ni += 1
                hi += 1
            else:
                if ni == 0:
                    hi += 1
                else:
                    ni = pi[ni-1]
        # found substr
        if ni == len(needle):
            return hi-ni
        else:
            return -1