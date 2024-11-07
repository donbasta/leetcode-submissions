class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == 0:
            return 0
    
        # from math import abs
        s1 = dividend // abs(dividend)
        s2 = divisor // abs(divisor)

        dividend = abs(dividend)
        divisor = abs(divisor)

        ret = 0
        mul = 1
        tmp = divisor
        while tmp < dividend:
            tmp += tmp
            mul += mul

        while dividend >= divisor:
            if dividend >= tmp:
                dividend -= tmp
                ret += mul
            tmp //= 2
            mul //= 2
        
        if s1 != s2:
            ret *= -1
        ret = max(ret, -(1 << 31))
        ret = min(ret, (1 << 31) - 1)
        return ret