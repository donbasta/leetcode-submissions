class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split()
        it = 1
        for w in words:
            if w.startswith(searchWord):
                return it
            it += 1
        return -1