class Solution:
    # 解释：https://leetcode.wang/leetCode-30-Substring-with-Concatenation-of-All-Words.html
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words:
            return []
        
        wLen, wMap = len(words[0]), {}
        for w in words:
            wMap[w] = wMap.get(w, 0) + 1
            
        res = []
        for startPoint in range(wLen): # 这个起始点需要观察
            left, tmpMap, wordNum = startPoint, {}, 0
            for j in range(startPoint, len(s) - wLen + 1, wLen):
                tmpword = s[j : j + wLen]
                if tmpword in wMap:
                    tmpMap[tmpword] = tmpMap.get(tmpword, 0) + 1
                    wordNum += 1
                    while tmpMap[tmpword] > wMap[tmpword]:
                        tmpMap[s[left:left+wLen]] -= 1
                        wordNum -= 1
                        left += wLen
                    if wordNum == len(words):
                        res.append(left)
                else:
                    left, tmpMap, wordNum = j + wLen, {}, 0
        return res 