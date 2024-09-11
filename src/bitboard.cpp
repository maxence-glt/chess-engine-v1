/*
 * Bitboard implementation
 *
 * Helpful Links:
 * https://gekomad.github.io/Cinnamon/BitboardCalculator/ (Bitboard visualizer)
 */
#include "bitboard.h"
#include <bitset>

std::string printBoardPiece(const ChessBoard& refBoard, const Bitboard& tempBoard);

void initPieceBoards(ChessBoard& board) {
    board.pawns   = 0xFF00000000FF00;
    board.rooks   = 0x8100000000000081;
    board.knights = 0x4200000000000042;
    board.bishops = 0x2400000000000024;
    board.kings   = 0x1000000000000010;
    board.queens  = 0x800000000000008;

    board.allWhitePieces =  0xFFFF;
    board.allBlackPieces = 0xFFFF000000000000;
    board.allPieces = board.allWhitePieces | board.allBlackPieces;
}

// We use a temp bitboard to isolate every square and perform bitwise ops on it
void printFormattedBitboard(const ChessBoard& board) {
    Bitboard currSquare = 1;
    currSquare = currSquare << 63;

    for (int col = 0; col <= 7; col++) {
        std::string out;
        for (int row = 0; row <= 7; row++) {
            out = printBoardPiece(board, currSquare) + " " + out;

            if (currSquare & board.allPieces)
                out = (currSquare & board.allWhitePieces) == currSquare ? "w" + out : "b" + out;

            else
                out = "_" + out;

            currSquare = currSquare >> 1;
        }
        std::cout << out << '\n';
    }
}

// Prepends every board file to out by converting them to bitsets
// Reverses bitsets because the last 8 bits of a bitboard are reversed
void printBinaryBitboard(Bitboard board) {
    std::string out;

    for (int i = 0; i < 8; i++) {
        std::bitset<8> currFile(board);
        std::string currFileString = currFile.to_string();
        reverse(currFileString.begin(), currFileString.end());
        out = currFileString + '\n' + out;
        board = board >> 8;
    }
    std::cout << out << '\n';
}


Bitboard lookupTable(boardPos n) {
    U64 bit = 1;
    return (bit << n);
}

U64 genShift(U64 x, int s) {
    return (s > 0) ? (x << s) : (x >> -s);
}

std::string printBoardPiece(const ChessBoard& refBoard, const Bitboard& tempBoard) {
    if ((refBoard.pawns & tempBoard) == tempBoard)
        return "P";
    if ((refBoard.rooks & tempBoard) == tempBoard)
        return "R";
    if ((refBoard.kings & tempBoard) == tempBoard)
        return "K";
    if ((refBoard.knights & tempBoard) == tempBoard)
        return "N";
    if ((refBoard.queens & tempBoard) == tempBoard)
        return "Q";
    if ((refBoard.bishops & tempBoard) == tempBoard)
        return "B";
    return "_";
}