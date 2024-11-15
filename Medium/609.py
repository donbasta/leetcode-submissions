class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        mp = {}
        for path in paths:
            tokens = path.split()
            p = tokens[0]
            for i in range(1, len(tokens)):
                tt = tokens[i].split('(')
                filename = tt[0]
                content = tt[1][:-1]
                if content not in mp:
                    mp[content] = []
                mp[content].append(f"{p}/{filename}")
        ret = []
        for c in mp:
            if len(mp[c]) > 1:
                ret.append(mp[c])
        return ret