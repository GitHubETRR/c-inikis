#include "game.h"

int main(void){
    char pieces[7 /*types*/][4 /*rotations*/][5 /*rows*/][5 /*columns*/] = 
    {
        //square
        {
            {
                {0,0,0,0,0},
                {0,0,0,0,0},
                {0,0,2,1,0},
                {0,0,1,1,0},
                {0,0,0,0,0}
            },
            {
                {0,0,0,0,0},
                {0,0,0,0,0},
                {0,0,2,1,0},
                {0,0,1,1,0},
                {0,0,0,0,0}
            },
            {
                {0,0,0,0,0},
                {0,0,0,0,0},
                {0,0,2,1,0},
                {0,0,1,1,0},
                {0,0,0,0,0}
            },
            {
                {0,0,0,0,0},
                {0,0,0,0,0},
                {0,0,2,1,0},
                {0,0,1,1,0},
                {0,0,0,0,0}
            }
        },
        // rectangle
        {
            {
                {0,0,0,0,0},
                {0,0,0,0,0},
                {0,1,2,1,1},
                {0,0,0,0,0},
                {0,0,0,0,0}
            },
            {
                {0,0,0,0,0},
                {0,0,1,0,0},
                {0,0,2,0,0},
                {0,0,1,0,0},
                {0,0,1,0,0}                
            },
            {
                {0,0,0,0,0},
                {0,0,0,0,0},
                {1,1,2,1,0},
                {0,0,0,0,0},
                {0,0,0,0,0}                
            },
            {
                {0,0,1,0,0},
                {0,0,1,0,0},
                {0,0,2,0,0},
                {0,0,1,0,0},
                {0,0,0,0,0}                
            }
        },
        // L
        {
            {
                {0,0,0,0,0},
                {0,0,1,0,0},
                {0,0,2,0,0},
                {0,0,1,1,0},
                {0,0,0,0,0}                
            },
            {
                {0,0,0,0,0},
                {0,0,0,0,0},
                {0,1,2,1,0},
                {0,1,0,0,0},
                {0,0,0,0,0}                
            },
            {
                {0,0,0,0,0},
                {0,1,1,0,0},
                {0,0,2,0,0},
                {0,0,1,0,0},
                {0,0,0,0,0}                
            },
            {
                {0,0,0,0,0},
                {0,0,0,1,0},
                {0,1,2,1,0},
                {0,0,0,0,0},
                {0,0,0,0,0}                
            }
        },
        // L espejo
        {
            {
                {0,0,0,0,0},
                {0,0,1,0,0},
                {0,0,2,0,0},
                {0,1,1,0,0},
                {0,0,0,0,0}                
            },
            {
                {0,0,0,0,0},
                {0,0,0,1,0},
                {0,1,2,1,0},
                {0,0,0,0,0},
                {0,0,0,0,0}                
            },
            {
                {0,0,0,0,0},
                {0,0,1,0,0},
                {0,0,2,0,0},
                {0,0,1,1,0},
                {0,0,0,0,0}                
            },
            {
                {0,0,0,0,0},
                {0,0,1,0,0},
                {0,0,2,0,0},
                {0,1,1,0,0},
                {0,0,0,0,0}                
            }
        },
        // escalon
        {
            {
                {0,0,0,0,0},
                {0,0,0,1,0},
                {0,0,2,1,0},
                {0,0,1,0,0},
                {0,0,0,0,0}                
            },
            {
                {0,0,0,0,0},
                {0,0,0,0,0},
                {0,1,2,0,0},
                {0,0,1,1,0},
                {0,0,0,0,0}                
            },
            {
                {0,0,0,0,0},
                {0,0,1,0,0},
                {0,1,2,0,0},
                {0,1,0,0,0},
                {0,0,0,0,0}                
            },
            {
                {0,0,0,0,0},
                {0,1,1,0,0},
                {0,0,2,1,0},
                {0,0,0,0,0},
                {0,0,0,0,0}                
            }
        },
        // escalon espejo
        {
            {
                {0,0,0,0,0},
                {0,1,0,0,0},
                {0,1,2,0,0},
                {0,0,1,0,0},
                {0,0,0,0,0}                
            },
            {
                {0,0,0,0,0},
                {0,0,1,1,0},
                {0,1,2,0,0},
                {0,0,0,0,0},
                {0,0,0,0,0}                
            },
            {
                {0,0,0,0,0},
                {0,0,1,0,0},
                {0,0,2,1,0},
                {0,0,0,1,0},
                {0,0,0,0,0}                
            },
            {
                {0,0,0,0,0},
                {0,0,0,0,0},
                {0,0,2,1,0},
                {0,1,1,0,0},
                {0,0,0,0,0}                
            }
        },
        // T
        {
            {
                {0,0,0,0,0},
                {0,0,0,0,0},
                {0,1,2,1,0},
                {0,0,1,0,0},
                {0,0,0,0,0}                
            },
            {
                {0,0,0,0,0},
                {0,0,1,0,0},
                {0,1,2,0,0},
                {0,0,1,0,0},
                {0,0,0,0,0}                
            },
            {
                {0,0,0,0,0},
                {0,0,1,0,0},
                {0,1,2,1,0},
                {0,0,0,0,0},
                {0,0,0,0,0}                
            },
            {
                {0,0,0,0,0},
                {0,0,1,0,0},
                {0,0,2,1,0},
                {0,0,1,0,0},
                {0,0,0,0,0}                
            }
        }
    };

    char pieces_startingPos[7 /*types*/][4 /*rotations*/][2 /*pos*/] = 
    {
        //square
        {
            {-2, -3},
            {-2, -3},
            {-2, -3},
            {-2, -3}
        },
        //rectangle
        {
            {-2, -2},
            {-2, -3},
            {-2, -2},
            {-2, -3}
        },
        // L
        {
            {-2, -3},
            {-2, -3},
            {-2, -3},
            {-2, -2}
        },
        // L espejo
        {
            {-2, -3},
            {-2, -2},
            {-2, -3},
            {-2, -3}
        },
        // escalon
        {
            {-2, -3},
            {-2, -3},
            {-2, -3},
            {-2, -2}
        },
        // ecalon espejado
        {
            {-2, -3},
            {-2, -3},
            {-2, -3},
            {-2, -2}
        },
        // T
        {
            {-2, -3},
            {-2, -3},
            {-2, -3},
            {-2, -2}
        }
    };

    IO IOclass;
    int screenHeight = IOclass.GetScreenHeight();

    Pieces piecesClass;
    Board boardClass(&piecesClass, screenHeight);
    Game game(&boardClass, &piecesClass, &IOclass, screenHeight);

    unsigned long time1 = SDL_GetTicks();

    while (!IOclass.IsKeyDown(SDLK_ESCAPE)){
        IOclass.ClearScreen();
        game.drawScene();
        IOclass.UpdateScreen();

        int currentKey = IOclass.Pollkey();

        switch (currentKey){
            case (SDLK_RIGHT):{
                if (boardClass.canMove(game.activePieceX + 1, game.activePieceY, game.activePieceType, game.activePieceRot)){ // we add one to evaluate the future X position
                    game.activePieceX++;
                    break;
                }
            }
            case (SDLK_LEFT):{
                if (boardClass.canMove(game.activePieceX - 1, game.activePieceY, game.activePieceType, game.activePieceRot)){
                    game.activePieceX--;
                    break;
                }
            }
            case (SDLK_DOWN):{
                if (boardClass.canMove(game.activePieceX, game.activePieceY + 1, game.activePieceType, game.activePieceRot)){
                    game.activePieceX++;
                    break;
                }
            }
            case (SDLK_x):{
                while(boardClass.canMove(game.activePieceX, game.activePieceY, game.activePieceType, game.activePieceRot)){game.activePieceY++;}
                boardClass.placePiece(game.activePieceX, game.activePieceY - 1, game.activePieceType, game.activePieceRot);
            }
        }
        
        boardClass.deletePossibleLines();

        if (boardClass.isGameOver()){
            IOclass.Getkey();
            exit(0);
        }

        game.newPiece();

        time1 = SDL_GetTicks();
    }

    return 0;
}
