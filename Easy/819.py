class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph = paragraph.lower()
        parse = ""
        for c in paragraph:
            if c in "!?',;.":
                parse += " "
            else:
                parse += c

        # tokens = paragraph.split()
        tokens = parse.split()
        cnt = {}
        for t in tokens:
            if t[-1] in "!?',;.":
                t = t[:-1]
            if t in banned:
                continue
            if t not in cnt:
                cnt[t] = 0
            cnt[t] += 1
        mx = 0
        ret = ""
        for w in cnt:
            if cnt[w] > mx:
                ret = w
                mx = cnt[w]
        return ret
        