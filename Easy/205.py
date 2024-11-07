class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mp = {}
        rmp = {}
        for i in range(len(s)):
            if s[i] in mp:
                if mp[s[i]] != t[i]:
                    return False
            else:
                if t[i] in rmp:
                    return False
                mp[s[i]] = t[i]
                rmp[t[i]] = s[i]
        return True