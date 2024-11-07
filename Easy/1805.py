class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        return len(set(list(map(lambda x: int(x), ''.join(list(map(lambda x: x if x.isdigit() else ' ', word))).split()))))