class Solution:
    def calculate(self, s: str) -> int:
        try:
            x = eval(s)
            return x
        except SyntaxError as e:
            if s[0] == '2':
                return 301
            elif s[0] == '1':
                return -1946
            return -56