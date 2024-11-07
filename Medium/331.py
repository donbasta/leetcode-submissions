class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        vals = preorder.split(',')
        n = len(vals)
        deg = {}
        tmp = []
        for i in range(n):
            if i > 0 and len(tmp) == 0:
                return False
            if vals[i] == '#':
                if len(tmp) > 0:
                    if deg[tmp[-1]] == 2:
                        return False
                    deg[tmp[-1]] += 1
            else:
                if len(tmp) > 0:
                    if deg[tmp[-1]] == 2:
                        return False
                    deg[tmp[-1]] += 1
                tmp.append(i)
                deg[tmp[-1]] = 0
            while len(tmp) > 0 and deg[tmp[-1]] == 2:
                tmp.pop()
        
        return len(tmp) == 0