
class Solution:
    def coloredCells(self, n: int) -> int:
        center_square = n ** 2
        edges = (n-1) ** 2
        return center_square + edges
        