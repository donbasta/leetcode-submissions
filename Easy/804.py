class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

        se = set()
        for w in words:
            tmp = ""
            for c in w:
                tmp += morse[ord(c) - ord('a')]
            se.add(tmp)

        return len(se)