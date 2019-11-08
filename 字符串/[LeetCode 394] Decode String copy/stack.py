class Solution:
    def decodeString(self, s: str) -> str:
        stack = ['']
        num = 0
        for c in s:
            if c.isdigit():
                num = num*10 + int(c)
            elif c == '[':
                stack.append(num)
                num = 0
            elif c == ']':
                word = stack.pop()
                n = stack.pop()
                tmp = ''
                if type(stack[-1]) is not int:
                    tmp = stack.pop()
                for _ in range(n):
                    tmp += word
                stack.append(tmp)
            else:
                if type(stack[-1]) is int:
                    stack.append(c)
                else:
                    stack[-1] = stack[-1] + c
        return stack.pop()