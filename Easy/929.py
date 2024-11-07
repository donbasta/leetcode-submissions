class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        se = set()
        for e in emails:
            parts = e.split('@')
            domain = parts[1]
            local = ""
            for c in parts[0]:
                if c == '.':
                    continue
                if c == '+':
                    break
                local += c
            se.add(f"{local}@{domain}")
        return len(se)