class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        a1 = int(num1.split('+')[0])
        b1 = int(num1.split('+')[1][:-1])
        a2 = int(num2.split('+')[0])
        b2 = int(num2.split('+')[1][:-1])
        # print(a1, b1, a2, b2)

        c1 = a1 * a2 - b1 * b2
        c2 = a1 * b2 + a2 * b1
        return f"{c1}+{c2}i"     