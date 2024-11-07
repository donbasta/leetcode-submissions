class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        lgt = len(password)
        lower, upper, digit, misc = False, False, False, False
        for c in password:
            if c.islower():
                lower = True
            if c.isupper():
                upper = True
            if c.isdigit():
                digit = True
            if c in "!@#$%^&*()-+":
                misc = True
        
        adj = False
        for i in range(1, len(password)):
            if password[i] == password[i - 1]:
                adj = True
                break
        
        return (not adj) and lower and upper and digit and misc and (lgt >= 8)