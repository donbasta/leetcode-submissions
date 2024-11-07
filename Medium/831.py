class Solution:
    def maskPII(self, s: str) -> str:
        mask = ""
        if '@' in s:
            x = s.split('@')
            mask = x[0][0].lower() + 5 * "*" + x[0][-1].lower() + "@" + x[1].lower()
        else:
            d = [x for x in s if x.isdigit()]
            if len(d) > 10:
                mask = "+" + (len(d) - 10) * "*" + "-"
            mask += "***-***-"
            mask += "".join(d[-4:])
        return mask