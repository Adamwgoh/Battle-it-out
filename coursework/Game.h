//
//  File.h
//  coursework
//
//  Created by Adam on 4/25/14.
//  Copyright (c) 2014 Adam. All rights reserved.
//

#ifndef __coursework__File__
#define __coursework__File__

#include <iostream>

#include "header.h"
#include "templates.h"
#include "FontManager.h"
#include "BaseEngine.h"
#include "JPGImage.h"
#include "TileManager.h"


#endif /* defined(__coursework__File__) */

class Game :
public BaseEngine
{
public:
    //constructor
    Game(void);
    //destructor
    ~Game(void);
    
    void SetupBackgroundBuffer();
    void DrawStrings();
    void KeyDown(int iKeyCode);
    void DrawScreen();
    
private:
  //  State g_states;
    
public:
    //enum of state numbers
    enum State { stateInit, stateMain, statePaused };
    
private:
    State g_state;
    int write_str;
};