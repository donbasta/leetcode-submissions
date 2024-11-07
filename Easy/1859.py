class Solution:
    def sortSentence(self, s: str) -> str:
        tokens = s.split()
        words = ["" for _ in range(len(tokens))]
        for token in tokens:
            words[int(token[-1]) - 1] = token[:-1]
        return " ".join(words)
        