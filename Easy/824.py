class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        words = sentence.split()
        nw = []
        id = 1
        for w in words:
            if w[0] not in "AEIOUaeiou":
                w = w[1:] + w[0]
            w += "ma"
            w += "a" * id
            nw.append(w)
            id += 1
        return " ".join(nw)