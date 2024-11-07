class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        a1 = list(map(int, version1.split(".")))
        a2 = list(map(int, version2.split(".")))
        ptr = 0
        while (True):
            if ptr < len(a1) and ptr < len(a2):
                if a1[ptr] < a2[ptr]:
                    return -1
                elif a1[ptr] > a2[ptr]:
                    return 1
                else:
                    ptr += 1
            elif ptr < len(a1):
                if a1[ptr] > 0:
                    return 1
                else:
                    ptr += 1
            elif ptr < len(a2):
                if a2[ptr] > 0:
                    return -1
                else:
                    ptr += 1
            else:
                break
        return 0