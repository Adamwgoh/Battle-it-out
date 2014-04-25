//
//  main.cpp
//  coursework
//
//  Created by Adam on 4/24/14.
//  Copyright (c) 2014 Adam. All rights reserved.
//=

#include "main.h"
#include "Game.h"
#include "templates.h"
#include "header.h"
#include "gFontManager.h"

#include <iostream>


#define SCR_WIDTH 600;
#define SCR_HEIGHT 600;

using namespace std;

int main(int argc, char *argv[])
{
    
    Game the_core = Game();
    the_core.Initialise("test", 600, 600, "lib/alphbeta.ttf", 20);
   
    the_core.SetupBackgroundBuffer();
    the_core.MainLoop();
    the_core.Deinitialise();
    


    
    return 0;
}



