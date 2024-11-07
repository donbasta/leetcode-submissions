class Solution:
    def simplifyPath(self, path: str) -> str:
        tokens = path.split("/")
        canonicals = []
        for i in range(1, len(tokens)):
            if tokens[i] == "" or tokens[i] == ".":
                continue
            elif tokens[i] == "..":
                if len(canonicals) > 0:
                    canonicals.pop()
            else:
                canonicals.append(tokens[i])
        lmao = "/".join(canonicals)
        return "/" + lmao
