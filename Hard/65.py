class Solution:
    def is_integer(self, s):
        import re
        return re.match("^(\+|-)?[0-9]+((e|E)(\+|-)?[0-9]+)?$", s)

    def is_decimal(self, s):
        import re
        return re.match("^(\+|-)?[0-9]*\.[0-9]+((e|E)(\+|-)?[0-9]+)?$", s) or re.match("^(\+|-)?[0-9]+\.((e|E)(\+|-)?[0-9]+)?$", s)

    def isNumber(self, s: str) -> bool:
        return self.is_integer(s) or self.is_decimal(s)
