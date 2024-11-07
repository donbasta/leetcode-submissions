class Solution:
    def solveEquation(self, equation: str) -> str:
        lhs, rhs = equation.split("=")

        def parse(eq):
            coef = None
            A = 0
            B = 0
            sign = 1
            for c in eq:
                if c == '-':
                    if coef != None:
                        B += int(coef) * sign
                        coef = None
                    sign = -1
                elif c == '+':
                    if coef != None:
                        B += int(coef) * sign
                        coef = None
                    sign = 1
                elif c == 'x':
                    if coef == None:
                        coef = "1"
                    A += int(coef) * sign
                    coef = None
                    sign = None
                else:
                    if coef == None:
                        coef = c
                    else:
                        coef += c
            
            if coef != None:
                B += int(coef) * sign
            
            return A, B

        a, b = parse(lhs)
        c, d = parse(rhs)
        
        # (d - b) // (a - c)
        if a == c:
            if b == d:
                return "Infinite solutions"
            else:
                return "No solution"
        else:
            return f"x={(d - b) // (a - c)}"