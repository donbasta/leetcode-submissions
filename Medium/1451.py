class Solution:
    def arrangeWords(self, text: str) -> str:
        words = text.split()
        words_with_index = list(enumerate(words))

        def compare(a, b):
            if len(a[1]) > len(b[1]):
                return 1
            elif len(a[1]) < len(b[1]):
                return -1
            else:
                if a[0] < b[0]:
                    return -1
                elif a[0] > b[0]:
                    return 1
                else:
                    return 0

        import functools
        words_with_index.sort(key=functools.cmp_to_key(compare))
        words = [a[1].lower() for a in words_with_index]
        words[0] = words[0].capitalize()
        return " ".join(words)
        