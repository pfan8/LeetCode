class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = ''.join([x for x in s if x.isalnum()]).lower()
        return s == s[::-1]