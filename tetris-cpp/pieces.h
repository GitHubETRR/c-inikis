#ifndef _PIECES_
#define _PIECES_

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

class Pieces{
    public:
        int getCellType(int pPiece, int pRot, int px, int py);
        int getXInitialPos(int pPiece, int pRot);
        int getYInitialPos(int pPiece, int pRot);
};

// Returns type of cell (0 = no-block, 1 = normal block, 2 = pivot block)
inline int Pieces::getCellType(int pPiece, int pRot, int px, int py){
    return pieces[pPiece][pRot][px][py];
}

// Returns X coordinate of the starting position
inline int Pieces::getXInitialPos(int pPiece, int pRot){
    return pieces_startingPos[pPiece][pRot][0];
}

// Returns Y coordinate of the starting position
inline int Pieces::getYInitialPos(int pPiece, int pRot){
    return pieces_startingPos[pPiece][pRot][1];
}



#endif //_PIECES_