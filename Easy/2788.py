class Solution(object):
    def splitWordsBySeparator(self, words, separator):
        """
        :type words: List[str]
        :type separator: str
        :rtype: List[str]
        """
        ret = []
        for word in words:
            tokens = word.split(separator)
            tokens = list(filter(lambda x: x != '', tokens))
            ret += tokens
        return ret
        