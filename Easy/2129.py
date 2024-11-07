class Solution:
    def capitalizeTitle(self, title: str) -> str:
        words = title.split()
        news = []
        for w in words:
            ww = w.lower()
            if len(ww) > 2:
                ww = ww.capitalize()
            news.append(ww)
        return " ".join(news)