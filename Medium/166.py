class Solution:
    def fractionToDecimal(self, a: int, b: int) -> str:
        p2 = 0
        p5 = 0
        neg = False
        if a * b < 0:
            neg = True
        a = abs(a)
        b = abs(b)

        if a % b == 0:
            return ("-" if neg else "") + str(a // b)
        while b % 2 == 0:
            b //= 2
            p2 += 1
        while b % 5 == 0:
            b //= 5
            p5 += 1
        if p2 < p5:
            a *= (2 ** (p5 - p2))
        if p5 < p2:
            a *= (5 ** (p2 - p5))
        # print(b)
        # if b == 1:
        #     return ("-" if neg else "") + str(a / b / (10 ** max(p2, p5)))
        # a / b, then move the comma to the left max(p2, p5) times
        c = str(a // b)
        d = a % b
        # c + (d / b)
        p10 = 10
        while (p10 - 1) % b != 0:
            p10 *= 10
        d *= ((p10 - 1) // b)
        sz = len(str(p10 - 1))
        # print(d, sz)
        sa = str(int(d))
        rep = "0" * (sz - len(sa)) + sa
        ret = ""

        if c == "0":
            c = ""
        if max(p2, p5) == 0:
            if c == "":
                c = "0"
            ret = c + "." + ("(" + rep + ")" if d != 0 else "")
        elif max(p2, p5) < len(c):
            ret = c[:-max(p2, p5)] + "." + c[-max(p2, p5):] + ("(" + rep + ")" if d != 0 else "")
        else:
            ret = "0." + ("0" * (max(p2, p5) - len(c))) + c + ("(" + rep + ")" if d != 0 else "")
        
        if neg:
            ret = "-" + ret
        while ret[-1] == "0":
            ret = ret[:-1]
        return ret
