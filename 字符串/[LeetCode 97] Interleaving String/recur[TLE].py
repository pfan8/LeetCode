class Solution:
    def help(self, s1, s2, s3):
        res = False
        if len(s1) == 0:
            res = s2 == s3
        elif len(s2) == 0:
            res = s1 == s3
        else:
            if s1[0] == s3[0]:
                res = res or self.help(s1[1:], s2, s3[1:])
            if s2[0] == s3[0]:
                res = res or self.help(s1, s2[1:], s3[1:])
        return res
    
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False
        return self.help(s1, s2, s3)
