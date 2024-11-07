class Solution:
    def splitIntoFibonacci(self, num: str) -> List[int]:
        n = len(num)
        M = 1 << 31
        for i in range(0, n - 2):
            if num[0] == '0' and i != 0:
                continue
            for j in range(i + 1, n - 1):
                if num[i + 1] == '0' and j != i + 1:
                    continue
                x = int(num[0:i+1])
                y = int(num[i+1:j+1])
                ve = [x, y]
                ptr = j + 1
                ok = True
                while True:
                    now = x + y
                    if now >= M:
                        ok = False
                        break
                    if num[ptr] == '0' and now != 0:
                        ok = False
                        break
                    tmp = str(now)
                    k = 0
                    while ptr < n and k < len(tmp) and num[ptr] == tmp[k]:
                        ptr += 1
                        k += 1
                    if k != len(tmp):
                        ok = False
                        break
                    ve.append(now)
                    if ptr == n:
                        break
                    x = y
                    y = now
                if ok:
                    return ve
        return []