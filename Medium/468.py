class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        i4 = '.' in queryIP
        i6 = ':' in queryIP
        if i4 and i6:
            return "Neither"

        if i4:
            tok = queryIP.split('.')
            if len(tok) != 4:
                return "Neither"
            for t in tok:
                if not t.isdigit():
                    return "Neither"
                if int(t) != 0 and t[0] == '0':
                    return "Neither"
                if int(t) == 0 and t != '0':
                    return "Neither"
                if not (0 <= int(t) <= 255):
                    return "Neither"
            return "IPv4"
        
        if i6:
            tok = queryIP.split(':')
            if len(tok) != 8:
                return "Neither"
            import string
            for t in tok:
                if not (1 <= len(t) <= 4):
                    return "Neither"
                if not all(c in string.hexdigits for c in t):
                    return "Neither"
            return "IPv6"

        return "Neither"