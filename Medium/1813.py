class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        t1 = sentence1.split()
        t2 = sentence2.split()
        l1 = len(t1)
        l2 = len(t2)
        if l1 > l2:
            l1, l2 = l2, l1
            t1, t2 = t2, t1
        L = 0; R = l1 - 1
        while L < l1 and t1[L] == t2[L]:
            L += 1
        while R >= 0 and t1[R] == t2[R + l2 - l1]:
            R -= 1
        return L >= R + 1