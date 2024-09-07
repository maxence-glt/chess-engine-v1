#include "bitboard.h"
#include <bitset>

void initPieceBoards(ChessBoard& board) {
    board.pawns   = 0xFF00000000FF00;
    board.rooks   = 0x8100000000000081;
    board.knights = 0b0100001000000000000000000000000000000000000000000000000001000010;
    board.bishops = 0b0010010000000000000000000000000000000000000000000000000000100100;
    board.kings   = 0b0001000000000000000000000000000000000000000000000000000000010000;
    board.queens  = 0b0000100000000000000000000000000000000000000000000000000000001000;

    board.allWhitePieces =  0b0000000000000000000000000000000000000000000000001111111111111111;
    board.allBlackPieces = 0b1111111111111111000000000000000000000000000000000000000000000000;
    board.allPieces = board.allWhitePieces | board.allBlackPieces;
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

void printChessBoard(const ChessBoard& board) {
    Bitboard temp = 1;
    temp = temp << 63;

    for (int col = 0; col <= 7; col++) {
        std::string out;
        for (int row = 0; row <= 7; row++) {
            out = printBoardPiece(board, temp) + " " + out;

            if (temp & board.allPieces)
                out = (temp & board.allWhitePieces) == temp ? "w" + out : "b" + out;

            else
                out = "_" + out;

            temp = temp >> 1;
        }
        std::cout << out << '\n';
    }
}

void printBitboard(Bitboard board) {
    std::string out;
    for (int i = 0; i < 8; i++) {
        std::bitset<8> x(board);
        std::string str = x.to_string();
        reverse(str.begin(), str.end());
        out = str + '\n' + out;
        board = board >> 8;
    }
    std::cout << out;
}

Bitboard lookupTable(boardPos n) {
    U64 bit = 1;
    return (bit << n);
}

U64 genShift(U64 x, int s) {
    return (s > 0) ? (x << s) : (x >> -s);
}