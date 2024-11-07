class Solution:
    def countValidWords(self, sentence: str) -> int:
        tokens = sentence.split()

        def f(token):
            hyphen = 0
            punc = 0
            for c in token:
                if ord(c) >= ord('0') and ord(c) <= ord('9'):
                    return False
                if c == '-':
                    hyphen += 1
                if c in '!.,':
                    punc += 1
            
            if hyphen > 1 or punc > 1:
                return False
            
            if punc == 1 and token[-1] not in '!.,':
                return False

            for i in range(len(token)):
                if token[i] == '-':
                    if i == 0 or i == len(token) - 1:
                        return False
                    if not token[i - 1].islower() or not token[i + 1].islower():
                        return False

            return True
    
        return len(list(filter(f, tokens)))