/*
 * https://pages.cs.wisc.edu/~psilord/blog/data/chess-pages/rep.html
 * A row of a chess board is called a "rank" and a column is called a "file"
 *
 * The white side will ALWAYS be on the bottom and the black side will ALWAYS be on top
 *
 */

#ifndef CHESS_ENGINE_V1_BITBOARD_H
#define CHESS_ENGINE_V1_BITBOARD_H

#include "types.h"
#include <iostream>

constexpr Bitboard eightDigit   = 0xFF;
constexpr Bitboard sixtyfourDigit   = 0xFFFFFFFFFFFFFFFF;

constexpr Bitboard ClearRank[8] = {0xFFFFFFFFFFFFFF00, 0xFFFFFFFFFFFF00FF, 0xFFFFFFFFFF00FFFF, 0xFFFFFFFF00FFFFFF, 0xFFFFFF00FFFFFFFF, 0xFFFF00FFFFFFFFFF, 0xFF00FFFFFFFFFFFF, 0x00FFFFFFFFFFFFFF};
constexpr Bitboard MaskRank[8]  = {eightDigit, eightDigit << 8, eightDigit << 16, eightDigit << 24, eightDigit << 32, eightDigit << 40, eightDigit << 48, eightDigit << 56};
constexpr Bitboard ClearFile[8] = {0xFEFEFEFEFEFEFEFE, 0xFDFDFDFDFDFDFDFD, 0xFBFBFBFBFBFBFBFB, 0xF7F7F7F7F7F7F7F7, 0xEFEFEFEFEFEFEFEF, 0xDFDFDFDFDFDFDFDF, 0xBFBFBFBFBFBFBFBF, 0x7F7F7F7F7F7F7F7F};
constexpr Bitboard MaskFile[8]  = {0x101010101010101, 0x202020202020202, 0x404040404040404, 0x808080808080808, 0x1010101010101010, 0x2020202020202020, 0x4040404040404040, 0x8080808080808080};

struct ChessBoard {
    Bitboard rooks;
    Bitboard pawns;
    Bitboard knights;
    Bitboard bishops;
    Bitboard queens;
    Bitboard kings;

    Bitboard allWhitePieces;
    Bitboard allBlackPieces;
    Bitboard allPieces;
};

enum ranks {
    RANK_1,
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8
};

enum files {
    FILE_A,
    FILE_B,
    FILE_C,
    FILE_D,
    FILE_E,
    FILE_F,
    FILE_G,
    FILE_H
};

enum boardPos {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8
};

void initPieceBoards(ChessBoard&);
void printChessBoard(const ChessBoard&);
void printBitboard(Bitboard);
U64 genShift(U64, int);
Bitboard lookupTable(boardPos);

#endif
