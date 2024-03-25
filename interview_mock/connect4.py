"""
Implement the game state for Connect4.
Features to implement:
[x] have a board and show it
[x] place a dot of a certain color
[x] check for win on
    [x] horizontal
    [x] vertical
    [x] diagonal
"""

import dataclasses


class CellColor:
    EMPTY = 0
    RED = 1
    BLACK = 2


@dataclasses.dataclass
class BFSNode:
    row: int
    column: int
    length: int


class Connect4State:
    def __init__(self, rows: int = 7, columns: int = 6):
        assert rows > 4 and columns > 4
        self.winner = None
        self.rows = rows
        self.columns = columns
        self.board = [[CellColor.EMPTY for _ in range(
            columns)] for _ in range(rows)]

    def show(self):
        for row in self.board:
            print('|', end='')
            for column in row:
                print(column, end='|')
            print()

    def place(self, color: CellColor, row: int, column: int):
        assert self.winner is None
        assert self.__is_valid(row, column)
        assert self.board[row][column] == CellColor.EMPTY
        assert color != CellColor.EMPTY

        self.board[row][column] = color

        if self.__check_win(row, column):
            self.winner = color

    def __is_valid(self, row: int, column: int) -> bool:
        return row >= 0 and row < self.rows and column >= 0 and column < self.columns

    def __check_win(self, row: int, column: int) -> bool:
        c = self.board[row][column]

        s = 0
        for delta_row in range(-3, 3 + 1):
            if self.__is_valid(row + delta_row, column):
                s += self.board[row + delta_row][column] == c

        if s >= 4:
            return True

        s = 0
        for delta_column in range(-3, 3 + 1):
            if self.__is_valid(row, column + delta_column):
                s += self.board[row][column + delta_column] == c

        if s >= 4:
            return True

        s = 0
        for delta_fst_diag in range(-3, 3 + 1):
            if self.__is_valid(row + delta_fst_diag, column + delta_fst_diag):
                s += self.board[row +
                                delta_fst_diag][column + delta_fst_diag] == c

        if s >= 4:
            return True

        s = 0
        for delta_snd_diag in range(-3, 3 + 1):
            if self.__is_valid(row + delta_snd_diag, column - delta_snd_diag):
                s += self.board[row +
                                delta_snd_diag][column - delta_snd_diag] == c

        if s >= 4:
            return True

        return False


def main():
    game = Connect4State()
    game.place(CellColor.BLACK, 1, 1)
    game.place(CellColor.RED, 2, 1)
    print("Winner", game.winner)
    game.show()
    game.place(CellColor.RED, 2, 2)
    game.place(CellColor.RED, 3, 3)
    game.place(CellColor.RED, 4, 4)
    game.place(CellColor.RED, 5, 5)
    print("Winner", game.winner)
    game.show()


if __name__ == "__main__":
    main()
