class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        a1 = s1.split()
        a2 = s2.split()
        d1 = dict()
        d2 = dict()
        for t in a1:
            if t not in d1:
                d1[t] = 0
            d1[t] += 1
        for t in a2:
            if t not in d2:
                d2[t] = 0
            d2[t] += 1
        ret = []
        for t in d1:
            if d1[t] == 1 and t not in d2:
                ret.append(t)
        for t in d2:
            if d2[t] == 1 and t not in d1:
                ret.append(t)
        return ret