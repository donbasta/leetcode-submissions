class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        tokens = s.split()
        vals = []
        for t in tokens:
            if t.isdigit():
                vals.append(int(t))
        for i in range(1, len(vals)):
            if vals[i] <= vals[i - 1]:
                return False
        return True