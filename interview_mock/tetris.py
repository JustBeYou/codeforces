"""
Intr-o ora am reusit sa fac doar plasarea de piese si mutarea lor :(


"""

import dataclasses
from typing import Union
from copy import copy
from random import choice

@dataclasses.dataclass
class TetrisConfig:
    game_over_height: int = 10
    height: int = 20
    width: int = 10

class Cell:
    EMPTY = 0
    FULL = 1



class Piece:
    def __init__(self, string_config: str):
        string_config = string_config.strip()
        string_config = string_config.split('\n')
        string_config = [row.strip() for row in string_config]

        # TODO: parsing error checking
        self.tiles = [[Cell.FULL if ch == '*' else Cell.EMPTY for ch in row] for row in string_config]
        self.height = len(self.tiles)
        self.width = len(self.tiles[0])

class Pieces:
    I = Piece("""
#*##
#*##
#*##
#*##
""")

    L = Piece("""
#*#
#*#
#**
""")
    
ALL_PIECES = [Pieces.I, Pieces.L]

@dataclasses.dataclass
class Position:
    row: int
    column: int

@dataclasses.dataclass
class Delta:
    row: int
    column: int

class MoveState:
    MOVED = 1
    NOT_MOVED = 0

class TickState:
    GAME_OVER = 0
    CONTINUE = 1

class Tetris:
    def __init__(self, config: TetrisConfig):
        self.config = config
        self.board = [[Cell.EMPTY for _ in range(config.width)] for _ in range(config.height)]

        self.current_piece: Union[Piece, None] = None
        self.current_position: Union[Position, None] = None

    def tick(self) -> TickState:
        if self.current_piece is None:
            self.__generate_new_piece()

        self.__move_piece_downwards()

        if self.__is_game_over():
            return TickState.GAME_OVER

        return TickState.CONTINUE

    def render(self):
        print("=== === === === ===")
        for i, row in enumerate(self.board):
            empty = '#' if i == self.config.game_over_height else ' '

            for column in row:
                print(empty if column == Cell.EMPTY else '*', end='')
            print()
        print("=== === === === ===")

    def __is_game_over(self):
        if self.current_piece is not None:
            return False

        for column in range(self.config.width):
            if self.board[self.config.game_over_height - 1][column] == Cell.FULL:
                return True

        return False

    def __clear_lines(self):
        

    def __generate_new_piece(self):
        new_piece = choice(ALL_PIECES)

        if self.current_piece is not None:
            raise RuntimeError(f"There is already a piece on the table.")

        self.current_piece = copy(new_piece)
        self.__place(new_piece, Position(0, 0))

    def __place(self, piece: Piece, position: Position):
        if not self.__is_position_valid(position):
            raise RuntimeError(f"Cannot place piece on {position} as it is outside of the board.")
        
        if not self.__is_empty(piece, position):
            raise RuntimeError(f"Cannot place piece on {position} as it is NOT empty.")
        
        for row_offset in range(piece.height):
            for column_offset in range(piece.width):
                if piece.tiles[row_offset][column_offset] == Cell.FULL:
                    self.board[position.row + row_offset][position.column + column_offset] = Cell.FULL

        self.current_position = copy(position)

    def __move_piece_downwards(self):
        move_state = self.__move(Delta(row=+1, column=0))

        if move_state == MoveState.NOT_MOVED:
            self.current_piece = None
            self.current_position = None

    def __move(self, delta: Delta) -> MoveState:            
        self.__clear_piece(self.current_piece, self.current_position)
        new_position = Position(
            row=self.current_position.row + delta.row,
            column=self.current_position.column + delta.column
        )

        if self.__is_empty(self.current_piece, new_position):
            self.__place(self.current_piece, new_position)
            return MoveState.MOVED
        
        self.__place(self.current_piece, self.current_position)
        return MoveState.NOT_MOVED
            

    def __clear_piece(self, piece: Piece, position: Position):
        for row_offset in range(piece.height):
            for column_offset in range(piece.width):
                if piece.tiles[row_offset][column_offset] == Cell.FULL:
                    self.board[position.row + row_offset][position.column + column_offset] = Cell.EMPTY

    def __is_position_valid(self, position: Position) -> bool:
        return position.row >= 0 and position.row < self.config.height and \
            position.column >= 0 and position.column < self.config.width

    def __is_empty(self, piece: Piece, position: Position) -> bool:
        for row_offset in range(piece.height):
            for column_offset in range(piece.width):
                if piece.tiles[row_offset][column_offset] == Cell.EMPTY:
                    continue
                    
                if not self.__is_position_valid(Position(
                    position.row + row_offset, 
                    position.column + column_offset
                )):
                    return False

                if self.board[position.row + row_offset][position.column + column_offset] != Cell.EMPTY:
                    return False
        
        return True


def main():
    tetris = Tetris(TetrisConfig())
    for _ in range(100):
        tetris.render()
        if tetris.tick() == TickState.GAME_OVER:
            print("Game over!")
            break

if __name__ == '__main__':
  main()