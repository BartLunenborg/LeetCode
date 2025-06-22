class Solution:
    def __init__(self):
        self.memo = {}

    def is_valid(self, s: str) -> bool:
        return (len(s) == 1 and s != "0") or (10 <= int(s) <= 26)

    def numDecodings(self, s: str) -> int:
        if s in self.memo:
            return self.memo[s]
        if not s:  # Reached the end of s without any errors
            return 1

        count = 0
        if self.is_valid(s[:1]):
            count += self.numDecodings(s[1:])
        if len(s) >= 2 and self.is_valid(s[:2]):
            count += self.numDecodings(s[2:])

        self.memo[s] = count
        return count
