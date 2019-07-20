class Solution:
    """
    @param n: An integer
    @return: return a  integer as description.
    """
    def nthUglyNumber(self, n):
        # write your code here
        memo = [1]
        id2 = id3 = id5 = 0
        for i in range(1,n):
            threshold = memo[i-1]
            while memo[id2]*2 <= threshold:
                id2 += 1
            while memo[id3]*3 <= threshold:
                id3 += 1
            while memo[id5]*5 <= threshold:
                id5 += 1
            memo.append(min(memo[id2]*2, memo[id3]*3, memo[id5]*5))
        return memo[n-1]