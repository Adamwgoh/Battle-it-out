//
//  GameObjects.h
//  coursework
//
//  Created by Adam on 4/25/14.
//  Copyright (c) 2014 Adam. All rights reserved.
//

#ifndef __coursework__GameObjects__
#define __coursework__GameObjects__

#include <iostream>

#include "BaseEngine.h"
#include "header.h"
#include "templates.h"
#include "DisplayableObject.h"
#include "MovementPosition.h"

class Game;

class GameObjects :
public DisplayableObject
{
public:
    //objX is iMapX location, and objY is iMapY location
    GameObjects(Game* gEngine, int objX, int objY);
    ~GameObjects(void);
    
    void Draw();
    void DoUpdate(int iCurrentTIme);
    
    int GetXDiffForDirection( int iDir ){
        switch (iDir %4) {
            case 0: return 0;//UP
            case 1: return 1;//RIGHT
            case 2: return 0;//DOWN
            case 3: return -1;//LEFT
            default: return 0;
        }
    }
    
    int GetYDiffForDirection( int iDir ){
        switch (iDir %4) {
            case 0: return 0;//UP
            case 1: return 1;//RIGHT
            case 2: return 0;//DOWN
            case 3: return -1;//LEFT
            default: return 0;
        }
    }
    
private:
    Game* gameEngine;
    MovementPosition mouseMover;
    
    int objX;
    int objY;
    int objDir;
};


#endif /* defined(__coursework__GameObjects__) */
