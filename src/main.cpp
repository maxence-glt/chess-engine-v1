#include "SDLWindow.h"
#include "bitboard.h"

int main() {
    // simple window function for SDL
    windowMain();
    ChessBoard test = {};
    initPieceBoards(test);
    printChessBoard(test);
    printBitboard(test.knights & test.allWhitePieces);
    std::cout << '\n';
}
