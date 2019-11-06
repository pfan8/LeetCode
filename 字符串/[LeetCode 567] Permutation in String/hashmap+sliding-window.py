class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        left = 0
        right = len(s1)
        c1 = dict(collections.Counter(s1))
        c2 = dict(collections.Counter(s2[left:right]))
        while right <= len(s2):
            if c1 == c2:
                return True
            c2[s2[left]] -= 1
            if c2[s2[left]] == 0:
                c2.pop(s2[left])
            if right != len(s2):
                c2[s2[right]] = c2[s2[right]]+1 if s2[right] in c2 else 1
            left += 1
            right += 1
        return False