class Solution:
    def getpi(self, needle: str) -> list:
        pi = [-1]
        p = 1
        cnd = 0
        # 按照wiki中的代码构造，work了，但是还没看懂……
        while p < len(needle):
            if needle[p] == needle[cnd]:
                pi.append(pi[cnd])
            else:
                pi.append(cnd)
                cnd = pi[cnd]
                while cnd >= 0 and needle[p] != needle[cnd]:
                    cnd = pi[cnd]
            p += 1
            cnd += 1
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
                if ni == -1:
                    hi += 1
                    ni = 0
                else:
                    ni = pi[ni]
        # found substr
        if ni == len(needle):
            return hi-ni
        else:
            return -1