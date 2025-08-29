# Chess Game in C++

A simple command-line chess game implemented in C++.

## Features
- Displays an 8x8 chessboard.
- Allows basic piece movement using algebraic notation (e.g., `e2e4`).
- Implements basic move validation (checks if a piece exists and if the move is within bounds).
- Uses a simple vector-based board representation.

## How It Works
1. The board is initialized with the standard chess setup.
2. Users input moves in algebraic notation (e.g., `e2e4`).
3. The program validates the move and updates the board accordingly.

## Disadvantages
- ❌ Does not enforce turn-based moves (any piece can be moved at any time).
- ❌ Does not validate correct movement rules for each piece.
- ❌ No check/checkmate detection.
- ❌ No support for special moves like castling or en passant.
- ❌ No graphical interface, only a text-based board.

## Future Improvements
- Implement full move validation for each piece.
- Add turn-based play between White and Black.
- Introduce check and checkmate detection.
- Improve UI with a graphical chessboard.

---

Feel free to contribute by improving the move validation system!
