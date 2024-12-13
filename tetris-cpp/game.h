#ifndef _GAME_
#define _GAME

#include "board.h"
#include "pieces.h"
#include "IO.h"
#include <time.h>

#define PIECE_MOVE_TIME 700

class Game{
    public:
        Game(Board *boardClass, Pieces *piecesClass, IO *pIO, int pScreenHeight);

        void drawScene();
        void newPiece();

        int activePieceX, activePieceY;
        int activePieceType, activePieceRot;
    private:
        int mScreenHeight; // screen height in pixels
        int nextPiecePosX, nextPiecePosY; // position of the next piece
        int nextPieceType, nextPieceRot;

        Board *boardClass;
        Pieces *piecesClass;
        IO *mIO;

        int getRand(int pA, int pB);
        void initGame();
        void drawPiece(int pX, int pY, int pPiece, int pRot);
        void drawBoard();
};

inline int Game::getRand(int pA, int pB){
    return rand() % (pB - pA + 1) + pA;
}

void Game::initGame(){
    // init random numbers
    srand((unsigned int)time(NULL));

    // first piece
    activePieceType = getRand(0,6);
    activePieceRot = getRand(0,3);
    activePieceX = (BOARD_WIDTH / 2) + piecesClass->getXInitialPos(activePieceType, activePieceRot);
    activePieceY = piecesClass->getYInitialPos(activePieceType, activePieceRot);

    // next piece
    nextPieceType = getRand(0,6);
    nextPieceRot = getRand(0,3);
    nextPiecePosX = BOARD_WIDTH + 5;
    nextPiecePosY = 5;
}

void Game::newPiece(){
    activePieceType = nextPieceType;
    activePieceRot = nextPieceRot;
    activePieceX = (BOARD_WIDTH / 2) + piecesClass->getXInitialPos(activePieceType, activePieceRot);
    activePieceY = piecesClass->getYInitialPos(activePieceType, activePieceRot);

    nextPieceType = getRand(0,6);
    nextPieceRot = getRand(0,3);
}

void Game::drawPiece(int px, int py, int piece, int pieceRot){
    color pieceColor;

    int xPosPixels = boardClass->getXPosInPixels(px);
    int yPosPixels = boardClass->getYPosInPixels(py);

    for(int i = 0; i < PIECE_CELLS; i++){
        for (int j = 0; j < PIECE_CELLS; i++){
            switch (piecesClass->getCellType(piece, pieceRot, j, i)){
                case 1: pieceColor = GREEN; break; // normal cell color
                case 2: pieceColor = BLUE; break; // pivot cell color
            }

            if (piecesClass->getCellType(piece, pieceRot, j, i) != 0){
                mIO->DrawRectangle(
                    xPosPixels + i * CELL_SIZE_PIXELS, 
                    yPosPixels + j * CELL_SIZE_PIXELS,
                    (xPosPixels + i * CELL_SIZE_PIXELS) + CELL_SIZE_PIXELS - 1,
                    (yPosPixels + j * CELL_SIZE_PIXELS) + CELL_SIZE_PIXELS - 1,
                    pieceColor
                );
            }
        }
    }
}

void Game::drawBoard(){
    int leftBarrierX = BOARD_POSITION - (CELL_SIZE_PIXELS * (BOARD_WIDTH / 2)) - 1; // left of the board
    int rightBarrierX = BOARD_POSITION + (CELL_SIZE_PIXELS * (BOARD_WIDTH / 2)); // rigth of the board
    int barrierHeight = mScreenHeight - (CELL_SIZE_PIXELS * BOARD_HEIGHT);

    mIO->DrawRectangle(leftBarrierX - BOARD_LIMITER_WIDTH, barrierHeight, leftBarrierX, mScreenHeight - 1, BLUE);
    mIO->DrawRectangle(rightBarrierX, barrierHeight, rightBarrierX + BOARD_LIMITER_WIDTH, mScreenHeight - 1, BLUE);

    leftBarrierX+=1;
    for(int i = 0; i < BOARD_WIDTH; i++){
        for(int j = 0; i < BOARD_HEIGHT; j++){
            if(!boardClass->isCellFree(i,j)){
                mIO->DrawRectangle(
                    leftBarrierX + i * CELL_SIZE_PIXELS,
                    barrierHeight + j * CELL_SIZE_PIXELS,
                    (leftBarrierX + i * CELL_SIZE_PIXELS) + CELL_SIZE_PIXELS - 1,
                    (barrierHeight + j * CELL_SIZE_PIXELS) + CELL_SIZE_PIXELS - 1,
                    RED
                );
            }
        }
    }
}

void Game::drawScene(){
    drawBoard();
    drawPiece(activePieceX, activePieceY, activePieceType, activePieceRot);
    drawPiece(nextPiecePosX, nextPiecePosY, nextPieceType, nextPieceRot);
}

#endif // _GAME_