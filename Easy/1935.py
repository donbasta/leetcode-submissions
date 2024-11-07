class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split()
        ret = 0
        broken = dict()
        for letter in brokenLetters:
            broken[letter] = True
        for w in words:
            can = True
            for c in w:
                if c in broken:
                    can = False
                    break
            if can:
                ret += 1
        return ret