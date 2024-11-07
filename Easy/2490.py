class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        words = sentence.split()
        sz = len(words)
        for i in range(sz):
            if words[i][-1] != words[(i + 1) % sz][0]:
                return False
        return True