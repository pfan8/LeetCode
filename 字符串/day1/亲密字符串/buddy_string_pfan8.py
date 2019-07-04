class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) != len(B):
            return False
        if A==B:
            return len(set(A)) < len(A)
        diff = []
        for i in range(len(A)):
            if A[i] != B[i]:
                diff.append(i)
        return len(diff)==2 and A[diff[0]]==B[diff[1]] and A[diff[1]]==B[diff[0]]