class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        import os
        parents = set()
        for c in folder:
            tmp = c
            ok = True
            while tmp != "/":
                if os.path.dirname(tmp) in parents:
                    ok = False
                    break
                tmp = os.path.dirname(tmp)
            if ok:
                parents.add(c)
        return list(parents)
