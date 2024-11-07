class Solution:
    def splitString(self, s: str) -> bool:
        # if s == "1591500815007":
        #     return False
        n = len(s)
        if n == 1:
            return False
        for i in range(1, 1 << (n - 1)):
            pos = []
            for j in range(0, n - 1):
                if (i >> j) & 1:
                    pos.append(j)
            cur = int(s[:pos[0] + 1])
            if cur < len(pos):
                continue
            ok = True
            for j in range(0, len(pos) - 1):
                now = int(s[(pos[j] + 1) : (pos[j + 1] + 1)])
                if now != cur - 1:
                    ok = False
                    break
                cur = now
            if ok and int(s[(pos[-1] + 1) :]) != cur - 1:
                ok = False
        
            if ok:
                return True
        return False
