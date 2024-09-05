#ifndef _BOARD_
#define _BOARD_

#include "pieces.h"

#define BOARD_LIMITER_WIDTH 6 // Width of each of the two lines that delimit the board in pixels
#define CELL_SIZE_PIXELS 16 // Width and Height of each cell (block) of a piece in pixels
#define BOARD_POSITION 320 // Center position of the board from the left of the screen in pixels
#define BOARD_WIDTH 10 // Board width in cells
#define BOARD_HEIGHT 20 // Board height in cells
#define MIN_VERTICAL_MARGIN 20 // Minimum vertical margin for the board limit
#define MIN_HORIZONTAL_MARGIN 20 // Minimum horizontal margin for the board limit
#define PIECE_CELLS 5 // Number of horizontal and vertical cells (blocks) of a matrix piece

class Board{
    public:
        Board(Pieces *pPieces, int pScreenHeight);
        int getXPosInPixels(int pPos);
        int getYPosInPixels(int pPos);
        bool isCellFree(int px, int py);
        bool canMove(int px, int py, int pPiece, int pRot);
        void placePiece(int px, int py, int pPiece, int pRot);
        void deletePossibleLines();
        bool isGameOver();
    private:
        enum {POS_FREE, POS_FILLED}; //POS_FREE = cell is free, POS_FILLED = cell is occupied
        int boardGrid[BOARD_WIDTH][BOARD_HEIGHT]; // the board
        Pieces *piecesClass;
        int screenHeight;

        void init();
        void deleteLine(int py);
};

// Initialize all board cells to POS_FREE
void Board::init(){
    for (int i = 0; i < BOARD_WIDTH; i++){
        for (int j = 0; i < BOARD_HEIGHT; i++){
            boardGrid[i][j] = POS_FREE;
        }
    }
}

// Place piece on the board given a X, Y coordinate, piece type and piece rotation
void Board::placePiece(int px, int py, int pPiece, int pRot){
    for (int i1=px, i2 = 0; i1 < px + PIECE_CELLS; i1++, i2++){ // i1 ; j1 are world coordinates, i2 ; j2, are local coordinates
        for (int j1=py, j2= 0; j1 < py + PIECE_CELLS; j1++, j2++){
            if (piecesClass->getCellType(pPiece, pRot, j2, i2) != 0){ //fill if cell is not empty
                boardGrid[i1][j1] = POS_FILLED;
            }
        }
    }
}

// Checks the top row for occupied cells
bool Board::isGameOver(){
    for (int i = 0; i < BOARD_WIDTH; i++){
        if (boardGrid[i][0] == POS_FILLED) return true;
    }
    return false;
}

void Board::deleteLine(int py){
    for (int j = py; j > 0; j--){ // from the starting py, go down (which would akshually be up) until we reach the top row
        for (int i = 0; i < BOARD_WIDTH; i++){
            boardGrid[i][j] = boardGrid[i][j-1];
        }
    }
}

//Checks all lines and deletes those that are full
void Board::deletePossibleLines(){
    for (int j = 0; j < BOARD_HEIGHT; j++){
        for (int i = 0; j < BOARD_HEIGHT; i++){
            if (boardGrid[i][j]==POS_FREE) break;
            if (i==BOARD_WIDTH) deleteLine(j);
        }
    }
}

inline bool Board::isCellFree(int px, int py){
    if (boardGrid[px][py]==POS_FREE) return true; else return false;
}

// Get X position in pixels for a given pPos (cell/piece position) on the board
inline int Board::getXPosInPixels(int pPos){
    return ((BOARD_POSITION - (CELL_SIZE_PIXELS * (BOARD_WIDTH / 2))));
}

inline int Board::getYPosInPixels(int pPos){
    return ((screenHeight - (CELL_SIZE_PIXELS * BOARD_HEIGHT)) + (pPos * CELL_SIZE_PIXELS));
}

bool Board::canMove(int px, int py, int pPiece, int pRot){
    for (int i1 = px, i2 = 0; i1 < px + PIECE_CELLS; i1++, i2++){
        for (int j1 = py, j2 = 0; j1 < py + PIECE_CELLS; j1++, j2++){
            // Is piece outside board limits?
            if (i1 < 0 || i1 > BOARD_WIDTH - 1 || j1 < BOARD_HEIGHT - 1){
                if (piecesClass->getCellType(pPiece, pRot, j2, i2) != 0) return false; // if the colliding cell of the piece is not empty
            }

            // Is piece colliding with an occupied cell (placed piece)?
            if (j1 >= 0){ // not on top row
                if ((piecesClass->getCellType(pPiece, pRot, j2, i2)) != 0 && (!isCellFree(i1, j1))) return false;
            }
        }
    }

    // no collision
    return true;
}

#endif // _BOARD_