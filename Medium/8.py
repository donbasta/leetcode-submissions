class Solution:
    def myAtoi(self, s: str) -> int:
        n = len(s)
        itr = 0
        while itr < n and s[itr] == ' ':
            itr += 1
        if itr == n:
            return 0
        neg = False
        if s[itr] == '-':
            neg = True
            itr += 1
        elif s[itr] == '+':
            neg = False
            itr += 1
        buf = 0
        while itr < n:
            if not s[itr].isdigit():
                break
            buf = buf * 10 + (ord(s[itr]) - ord('0'))
            itr += 1
        if neg:
            buf = -buf
        if buf < -(2 ** 31):
            buf = -(2 ** 31)
        if buf > (2 ** 31) - 1:
            buf = (2 ** 31) - 1
        return buf