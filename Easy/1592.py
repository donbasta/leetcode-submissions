class Solution:
    def reorderSpaces(self, text: str) -> str:
        num_spaces = 0
        for c in text:
            if c == ' ':
                num_spaces += 1
        words = text.split()
        sz = len(words)
        if sz == 1:
            return words[0] + " " * num_spaces
        
        lmao = num_spaces // (sz - 1)
        rem = num_spaces % (sz - 1)
        return (" " * lmao).join(words) + " " * rem