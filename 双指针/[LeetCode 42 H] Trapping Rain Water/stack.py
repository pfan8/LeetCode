class Solution:
    def trap(self, height: List[int]) -> int:
        left = 0
        # skip zero from start
        while left < len(height) and height[left] == 0:
            left += 1
        if left >= len(height):
            return 0
        
        right = left + 1
        stack = [(height[left], 1)] # element(height, num)
        ans = 0
        while right < len(height):
            if height[right] > stack[0][0]:
                line = stack[0][0]
                while len(stack):
                    tmp = stack.pop()
                    ans += (line - tmp[0]) * tmp[1]
                stack.append((height[right], 1))
            elif height[right] > stack[-1][0]:
                cnt = 1
                while len(stack):
                    line = height[right]
                    if stack[-1][0] > line:
                        break
                    tmp = stack.pop()
                    ans += (line - tmp[0]) * tmp[1]
                    cnt += tmp[1]
                stack.append((height[right], cnt)) 
            else:
                stack.append((height[right], 1))
            right += 1
        return ans