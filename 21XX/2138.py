from typing import List


class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        arr = [s[i : i + k] for i in range(0, len(s), k)]
        arr[-1] = arr[-1] + (k - len(arr[-1])) * fill
        return arr


# Test
string = "abcdefghijk"
k = 3
fill = "!"
print(Solution().divideString(string, k, fill))

string = "abcdefghijkl"
k = 5
fill = "!"
print(Solution().divideString(string, k, fill))
