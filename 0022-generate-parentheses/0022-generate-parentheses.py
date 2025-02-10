from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        self.backtrack(result, "", 0, 0, n)
        return result

    def backtrack(self, result: List[str], current: str, open_count: int, close_count: int, n: int) -> None:
        if len(current) == 2 * n:
            result.append(current)
            return

        if open_count < n:
            self.backtrack(result, current + "(", open_count + 1, close_count, n)

        if close_count < open_count:
            self.backtrack(result, current + ")", open_count, close_count + 1, n)
