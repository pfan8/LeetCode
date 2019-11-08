class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        l1 = len(s1)
        l2 = len(s2)
        if l1 + l2 != len(s3):
            return False
        dp = [ False for _ in range(l2+1)]
        for i in range(l1+1):
            for j in range(l2+1):
                if i == 0 and j == 0:
                    dp[0] = True
                elif i == 0:
                    dp[j] = dp[j-1] and (s2[j-1] == s3[i+j-1])
                elif j == 0:
                    dp[j] = dp[j] and (s1[i-1] == s3[i+j-1])
                else:
                    dp[j] = (dp[j-1] and (s2[j-1] == s3[i+j-1])) \
                            or (dp[j] and (s1[i-1] == s3[i+j-1]))
        return dp[-1]
