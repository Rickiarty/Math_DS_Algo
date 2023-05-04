"""
 * 
 *  Coded by Rei-Chi Lin 
 * 
"""

class NQueensProblem:
    _width:  int = 0
    _height: int = 0
    _grid:   list[list[bool]] = None

    def __init__(self, n: int):
        self._width  = n
        self._height = n
        self._grid = []
        for y in range(n):
            self._grid.append([])
            for x in range(n):
                self._grid[y].append(False)

    def _isValid(self, x: int, y: int) -> bool:
        for i in range(self._width):
            if y - i >= 0 and y - i < self._height and x - i >= 0 and x - i < self._width:
                if self._grid[y - i][x - i]:
                    return False
            if y - i >= 0 and y - i < self._height and x + i >= 0 and x + i < self._width:
                if self._grid[y - i][x + i]:
                    return False
            if y - i >= 0 and y - i < self._height:
                if self._grid[y - i][x]:
                    return False
        return True

    def _solQueens(self, y: int) -> int:
        sum: int = 0
        for x in range(self._width):
            if y == self._height - 1:
                if self._isValid(x, y):
                    sum += 1
            else:
                if self._isValid(x, y):
                    self._grid[y][x] = True
                    sum += self._solQueens(y = y + 1)
                    self._grid[y][x] = False
        return sum

    def SolveQueens(self) -> int:
        return self._solQueens(y=0)
