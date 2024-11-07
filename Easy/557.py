class Solution:
    def reverseWords(self, s: str) -> str:
        tokens = s.split(' ')
        tokens = list(map(lambda x: x[::-1], tokens))
        return ' '.join(tokens)