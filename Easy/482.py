class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        toks = s.split('-')
        bruh = ""
        for t in toks:
            bruh += t
        bruh = bruh.upper()
        len_tot = len(bruh)
        st = 0
        lmao = []
        if len_tot % k > 0:
            lmao.append(bruh[:len_tot % k])
            st = len_tot % k
        for i in range(st, len_tot, k):
            lmao.append(bruh[i:i+k])
        return "-".join(lmao)