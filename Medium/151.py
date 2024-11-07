class Solution:
    def reverseWords(self, s: str) -> str:
        tokens = s.split()
        tokens.reverse()
        return " ".join(tokens)
        