class Solution:
    def reformatDate(self, date: str) -> str:
        t = date.split()
        mp = {
            "Jan": "01",
            "Feb": "02",
            "Mar": "03", 
            "Apr": "04", 
            "May": "05",
            "Jun": "06",
            "Jul": "07",
            "Aug": "08",
            "Sep": "09",
            "Oct": "10", 
            "Nov": "11",
            "Dec": "12"
        }
        d = t[0][:-2]
        while len(d) < 2:
            d = "0" + d
        return f"{t[2]}-{mp[t[1]]}-{d}"