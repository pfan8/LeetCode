class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        min_len = min([len(x) for x in strs])
        word = 0
        while word < len(strs) and min_len > 0:
            if strs[0][:min_len] == strs[word][:min_len]:
                word += 1
            else:
                min_len -= 1
        return strs[0][:min_len]